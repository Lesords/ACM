#include<iostream>//ac
#include<cstring>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;

//题解：线性dp
//根据请求以及各个员工的位置来当做状态
//由于满足第i个要求的时候，肯定有一个员工处于要求的位置
//所以只需要记录其他两个员工的位置即可（可缩小一维
//那么将初始化数组为最大值
//对于边界位置需为 f[0][1][2] = 0，表示当前0个请求，且其中两个员工处于1和2位置
//那么对于第三个员工来说，可以将其存储在要求a[0]中，即a[0] = 3
//那么对于每次的计算过程中，都有三种转移的可能性
//即将三个员工分别移到a[i]（当前要求的位置）中去
//注意：需要判断员工的位置是否相同
//目的结果：满足m个要求时，员工处于任意位置，取最小值

const int MAXN = 205;
const int MAXM = 1e3+5;
int c[MAXN][MAXN],a[MAXM];//c数组存储移动花费，a为要求数组
int dp[MAXM][MAXN][MAXN];//dp[i][j][k]：为满足i个要求时，其他两个员工处于j和k的位置
int main() {
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) cin>>c[i][j];
    }
    for(int i = 1;i <= m;i++) cin>>a[i];
    memset(dp,0x3f,sizeof(dp));                         //初始化为无穷大
    a[0] = 3;                                           //记录员工位置，初始化
    dp[0][1][2] = 0;                                    //当前花费为0
    int ans = INF;
    for(int i = 1;i <= m;i++) {                         //要求
        for(int j = 1;j <= n;j++) {
            for(int k = 1;k <= n;k++) {
                //等于INF说明状态不存在
                if(dp[i-1][j][k]!=INF) {                //从上一个状态往后推
                    //需要特判员工位置
                    if(j!=a[i]&&k!=a[i]) {              //员工 a[i-1] 移到 a[i]
                        dp[i][j][k] = min(dp[i][j][k], dp[i-1][j][k]+c[a[i-1]][a[i]]);
                    }
                    if(j!=a[i]&&a[i-1]!=a[i]) {         //员工 k 移到 a[i]
                        dp[i][j][a[i-1]] = min(dp[i][j][a[i-1]], dp[i-1][j][k]+c[k][a[i]]);
                    }
                    if(k!=a[i]&&a[i-1]!=a[i]) {         //员工 j 移到 a[i]
                        dp[i][a[i-1]][k] = min(dp[i][a[i-1]][k], dp[i-1][j][k]+c[j][a[i]]);
                    }
                }
            }
        }
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            ans = min(ans, dp[m][i][j]);                //是m不是n，m为服务次数！！！
        }
    }
    cout<<ans<<"\n";
    return 0;
}
