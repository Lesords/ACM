#include<iostream>//tle
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
const int MAXN = 1e6+5;
ll dp[MAXN],a[MAXN],b[MAXN];
int main() {
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF) {
        for(int i = 1;i <= n;i++) scanf("%lld%lld",&a[i],&b[i]),dp[i] = 0;
        for(int i = 1;i <= n;i++) {
            for(int j = m;j >= a[i];j--) {
                dp[j] = max(dp[j],dp[j-a[i]]+b[i]);
            }
        }
        printf("%lld\n",dp[m]);
    }
	return 0;
}
