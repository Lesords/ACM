#include<iostream>//ac 前缀和
#include<cstdio>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;

//题解：将一个数向前移动k位时
//值 = 初始总和扣除a[i]*k再加上 前一位到前k位的区间和
//从k+1到n之间开始查询，修改最大值

const int MAXN = 1e5+5;
ll a[MAXN],sum[MAXN],n,k;
int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		ll tot = 0,ans = 0;//初始化为0
		scanf("%lld%lld",&n,&k);
		for(ll i = 1;i <= n;i++) {
			scanf("%lld",&a[i]),tot += a[i]*i;//tot总和
			sum[i] = (i>1?sum[i-1]:0) + a[i];//前缀和
		}
		for(int i = k+1;i <= n;i++) {
			ll tmp = tot-a[i]*k+(sum[i-1]-sum[i-1-k]);
			ans = max(ans,tmp);//更新最大值
		}
		printf("%lld\n",ans);
	}
	return 0;
}
