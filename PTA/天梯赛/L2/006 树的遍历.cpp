#include<iostream>//ac
#include<vector>
#include<algorithm>
using namespace std;

//题解：利用后序遍历序列的根节点来确定左右子树，然后继续递归
//记录每个点的深度，然后利用vector存储对应深度的节点
//最后遍历所有深度出现的节点即可

const int MAXN= 35;
int tree[MAXN],l[MAXN],r[MAXN],a[MAXN],b[MAXN],hei[MAXN];
//tree记录树节点的值，l、r分别为左右子儿子的编号，a、b分别为后序遍历和中序遍历
//hei记录树节点的深度
vector<int> ans[MAXN];//存储对应深度的树节点
int n,cnt,height;//cnt为树的节点编号，height为数的最大深度
void solve(int rt,int left,int right,int L,int R) {
    //rt为当前根节点，left、right为中序遍历的范围，L、R为后序遍历的范围
    tree[rt] = a[R];
    if(left==right) return;//只有一个节点则返回
    int pos = 0,Lnum = 0,Rnum = 0;//pos为根节点在中序遍历的位置
    //Lnum为左子树节点数，Rnum为右子树节点数
    for(int i = left;i <= right;i++) {
        if(b[i]==a[R]) {//寻找根节点位置
            pos = i;break;
        }//位置一定能找到，所以根节点初始化任意值即可
    }
    Lnum = pos-left;//分别计算左右子树数量
    Rnum = right-pos;
    if(pos>left) {//存在左子树
        ++cnt;
        l[rt] = cnt;//记录左儿子的编号
        hei[cnt] = hei[rt]+1;//记录深度
        height = max(height,hei[cnt]);//计算树的深度
        ans[hei[cnt]].push_back(cnt);//记录对应深度的树节点
        solve(cnt,left,pos-1,L,L+Lnum-1);//继续递归
    }
    if(pos<right) {//存在右子树
        ++cnt;
        r[rt] = cnt;//记录右儿子的编号
        hei[cnt] = hei[rt]+1;//记录深度
        height = max(height,hei[cnt]);//计算树的深度
        ans[hei[cnt]].push_back(cnt);//记录对应深度的树节点
        solve(cnt,pos+1,right,R-Rnum,R-1);//继续递归
    }
}
int main() {
    cin>>n;
    for(int i = 1;i <= n;i++) {
        cin>>a[i];
    }
    for(int i = 1;i <= n;i++) {
        cin>>b[i];
    }
    cnt = 1;
    hei[1] = ++height;
    ans[1].push_back(1);//初始化为根节点
    solve(1,1,n,1,n);
    int flag = 0;
    for(int i = 1;i <= height;i++) {//遍历所有深度
        for(int j = 0;j < ans[i].size();j++) {
            int dot = ans[i][j];//记录的是节点编号
            if(flag) cout<<" ";
            else flag = 1;
            cout<<tree[dot];//输出节点值
        }
    }
    return 0;
}
