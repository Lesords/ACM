#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;

//题解：利用两个状态来建立转移方程
//每次根据当前边的长度来判断如何修改

const int MOD = 1e9+7;
ll dp[105][2];//dp[i][0/1]：i表示权值和，0表示没有一个边为d，1为有边长为d
int main() {
    int n,k,d;
    cin>>n>>k>>d;
    dp[0][0] = 1;//初始化为1（和为0，即边权也都小于d
    for(int i = 1;i <= n;i++) {
        dp[i][0] = dp[i][1] = 0;//初始化为0
        for(int j = 1;j <= min(i,k);j++) {//边权不能超过当前总和i
            if(j>=d) {//边权大于标准d
                dp[i][1] = (dp[i][1]+dp[i-j][0])%MOD;//i-j的两个状态都可叠加
                dp[i][1] = (dp[i][1]+dp[i-j][1])%MOD;
            }
            else {//否则，只能取对应状态
                dp[i][1] = (dp[i][1]+dp[i-j][1])%MOD;
                dp[i][0] = (dp[i][0]+dp[i-j][0])%MOD;
            }
        }
    }
    cout<<dp[n][1];
    return 0;
}
