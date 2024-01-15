#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;

//题意：给定的是花的数量区间，不是两种花的数量！！！
//i数量花分为：一个红花和k个白花
//可得状态方程为：dp[i] = dp[i-1]+dp[i-k]
//然后用前缀和记录结果，查询区间的时候注意 +MOD

const ll MOD = 1e9+7;
const int MAXN = 1e5+5;
ll sum[MAXN],dp[MAXN];
int main() {
    int t,k;
    cin>>t>>k;
    dp[0] = 1;//初始化为1
    for(int i = 1;i < MAXN;i++) {
        dp[i] = (dp[i]+dp[i-1])%MOD;//一朵红花
        if(i>=k) {
            dp[i] = (dp[i]+dp[i-k])%MOD;//k朵白花
        }
    }
    for(int i = 1;i < MAXN;i++) {//前缀和
        sum[i] = (sum[i-1]+dp[i])%MOD;
    }
    while(t--) {
        int a,b;
        cin>>a>>b;//区间取和记得+MOD，不然会出现负数！！！
        cout<<(sum[b]-sum[a-1]+MOD)%MOD<<"\n";
    }
    return 0;
}
