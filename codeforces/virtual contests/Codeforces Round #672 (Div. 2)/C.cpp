#include<iostream>//ac
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<utility>
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;
const int MAXN = 3e5+5;
ll a[MAXN],dp[MAXN][2];//dp[i][0]表示i为正时的值，dp[i][1]表示i为负时的值
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,q;cin>>n>>q;
        for(int i = 1;i <= n;i++) cin>>a[i];
        dp[1][0] = a[1];
        for(int i = 2;i <= n;i++) {
            dp[i][0] = max(dp[i-1][0],max(a[i],dp[i-1][1]+a[i]));
            dp[i][1] = max(dp[i-1][1],dp[i-1][0]-a[i]);
        }
        cout<<max(dp[n][0],dp[n][1])<<endl;
    }
	return 0;
}
