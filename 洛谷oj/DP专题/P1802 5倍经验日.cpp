#include<iostream>//ac
#include<algorithm>
using namespace std;
const int MAXN = 1e3+5;
int dp[MAXN],win[MAXN],lose[MAXN],use[MAXN];
//dp[i]:用了i个药所获得的经验
int main() {
    int n,x;
    cin>>n>>x;
    for(int i = 1;i <= n;i++)
        cin>>lose[i]>>win[i]>>use[i];
    for(int i = 1;i <= n;i++) {//遍历所有药
        for(int j = x;j >= use[i];j--) {//可以赢的情况
            dp[j] = max(dp[j-use[i]]+win[i],dp[j]+lose[i]);
            //赢消耗use[i],输不消耗
        }
        //肯定输的情况
        for(int j = use[i]-1;j >= 0;j--) dp[j] += lose[i];
    }
    cout<<dp[x]*5LL<<endl;//longlong！！！
    return 0;
}
