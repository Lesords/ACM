#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;

//题解：区间dp
//由于题目给出的是中序遍历
//所以说就是对于这个遍历结果取个根节点，根节点的值加上两边区间结果相乘的值即可
//对于最后前序遍历，则在每次计算过程中取区间的根节点即可
//边界状态：dp[i][i] = a[i] 单个节点值为本身
//状态: [l,r] 表示二叉树[l,r]的最大分数值
//转移：dp[i][k-1]*dp[k+1][j] + dp[k][k],  i < k < j
//特判根为i或j位置的时候
//目的状态：dp[1][n]

const int MAXN = 33;
int a[MAXN],root[MAXN][MAXN];//root记录对应区间的根节点
ll dp[MAXN][MAXN];
void print_path(int l,int r,int flag) {//输出l到r区间的前序遍历，flag判断是否输出空格
    if(l>r) return ;
    if(flag) cout<<" ";//除了第一个位置，其他都要输出空格
    cout<<root[l][r];
    if(l==r) return;//若为叶子，直接返回
    print_path(l, root[l][r]-1,1);//左子树
    print_path(root[l][r]+1, r,1);//右子树
}
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        cin>>a[i];
        dp[i][i] = a[i];                //边界状态
        root[i][i] = i;                 //记录根节点为本身
    }
    for(int len = 1;len < n;len++) {    //先长度
        for(int i = 1;i <= n;i++) {     //后起点
            int j = i+len;              //计算终点
            dp[i][j] = dp[i][i]+dp[i+1][j];//先取i为根节点
            root[i][j] = i;             //记录根节点
            for(int k = i+1;k <= j;k++) {//遍历区间，令当前点为根节点
                if(k==j) {              //若最后一个数为根节点，特判！！！
                    if(dp[i][j] < dp[k][k]+dp[i][k-1]) {
                        dp[i][j] = dp[k][k]+dp[i][k-1];//取最小值
                        root[i][j] = k; //更新根节点
                    }
                }
                else {
                    if(dp[i][j] < dp[k][k]+dp[i][k-1]*dp[k+1][j]) {
                        dp[i][j] = dp[i][k-1]*dp[k+1][j] + dp[k][k];
                        root[i][j] = k; //更新分数及根节点编号
                    }
                }
            }
        }
    }
    cout<<dp[1][n]<<"\n";
    print_path(1,n,0);//先序遍历
    return 0;
}
