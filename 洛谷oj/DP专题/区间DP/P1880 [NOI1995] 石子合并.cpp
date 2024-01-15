#include<iostream>//ac
#include<cstring>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;

//题解：区间dp
//注意：题目中的石子是环形的，所以需要重复一段石子，来记录环形的情况
//由于多出来的一段是用来方便计算的，所以计算的区间长度还是为n！！！
//令 区间[l,r] 为状态
//遍历所有 l <= k < r，取对应的最小值和最大值
//取最小值的时候，需要把数组初始化为最大值，边界情况初始化为0
//边界情况为单个区间合并，即不需要合并，得分为0

const int MAXN = 205;
int a[MAXN],sum[MAXN],f_up[MAXN][MAXN],f_down[MAXN][MAXN];
//a为原序列，sum为前缀和序列
//f_up[i][j]：为区间[i,j]合并成一堆花费的最大得分
//f_down[i][j]：为区间[i,j]合并成一堆花费的最小得分
int main() {
    memset(f_down, 0x3f, sizeof(f_down));   //初始化为最大值
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        cin>>a[i];
        sum[i] = sum[i-1]+a[i];             //记录前缀和
        f_down[i][i] = 0;                   //边界值为0
    }
    for(int i = n+1;i <= n*2;i++) {         //重复一段
        a[i] = a[i-n];                      //记录对应值
        sum[i] = sum[i-1]+a[i];             //前缀和
        f_down[i][i] = 0;                   //边界值为0
    }
    for(int len = 1;len < n;len++) {        //先遍历区间大小
        for(int i = 1;i+len <= n*2;i++) {   //遍历起点，判断下不能越界
            int j = i+len;                  //终点可以直接计算
            for(int k = i;k < j;k++) {      //中间的分割点，分割点可以包括起点但不包括终点！！！
                //计算对应的最小得分和最大得分
                f_down[i][j] = min(f_down[i][j], f_down[i][k]+f_down[k+1][j]+sum[j]-sum[i-1]);
                f_up[i][j] = max(f_up[i][j], f_up[i][k]+f_up[k+1][j]+sum[j]-sum[i-1]);
            }
        }
    }
    int ans_min = INF,ans_max = 0;
    for(int i = 1;i <= n;i++) {             //取每个i为起点且长度为n的区间的最值即可
        ans_min = min(ans_min, f_down[i][i+n-1]);//区间长度为n，即为[i,i+n-1]！！！
        ans_max = max(ans_max, f_up[i][i+n-1]);
    }
    cout<<ans_min<<"\n"<<ans_max;
    return 0;
}
