#include<iostream>//ac
#include<algorithm>
using namespace std;
const int MAXN = 105;

//题解：动态规划
//状态方程为：dp[i][j] = min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1
//dp[i][j]:以(i,j)为右下角，可以形成的最大正方形的边长

int dp[MAXN][MAXN];
int main() {
    int n,m,ans = 0;
    cin>>n>>m;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            int tmp;
            cin>>tmp;
            if(tmp) {//计算当前值，并更新答案
                dp[i][j] = min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
                ans = max(ans,dp[i][j]);
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}
