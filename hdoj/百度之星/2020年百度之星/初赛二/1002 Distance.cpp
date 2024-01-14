#include<iostream>//ac
#include<cstdio>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;
const int MAXN = 1e5+5;
ll a[MAXN],suf[MAXN];
int main() {
	int t,n;
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		ll ans = 0;
		for(int i = 1;i <= n;i++) scanf("%lld",&a[i]);
		sort(a+1,a+n+1);//需要排序！！！
		suf[n] = a[n];
		for(int i = n-1;i >= 1;i--) {
			suf[i] = suf[i+1]+a[i];//后缀和
		}
		for(int i = 1;i < n;i++) {
			//后缀和-(n-i)个a[i]即为i与右边剩余朋友的总距离
			ans += suf[i+1]-a[i]*(n-i);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
