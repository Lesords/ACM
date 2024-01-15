#include<cstdio>//ac
#include<iostream>
#include<algorithm>
#define INF 0x3f3f3f3f3f3f3f3f
#define ll long long
using namespace std;
const int MAXN = 2e5+5;
ll a[MAXN],sum[MAXN];
int main() {
	int t,n,k;
	scanf("%d",&t);
	while(t--) {
		scanf("%d%d",&n,&k);
		for(int i = 1;i <= n;i++) {
			scanf("%lld",&a[i]);
			sum[i] = sum[i-1]+a[i];//前缀和
		}
		ll ans = -INF,maxx = -INF;//INF不能过短
		for(int i = k;i+k <= n;i++) {
			maxx = max(maxx,sum[i]-sum[i-k]);
			//maxx为i即i前的 k区间 最大值
			ans = max(ans,maxx+sum[i+k]-sum[i]);
			//ans更新为 前多个区间取大值 + 后一个区间 的较大值
		}
		//前多 + 后1 的更新方式
		printf("%lld\n",ans);
	}
	return 0;
}
