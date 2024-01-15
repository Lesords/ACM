#include<iostream>//ac
#include<cstdio>
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int MAXN = 2e5+5;
ll a[MAXN],dp[MAXN],maxx = -INF;//设为负值（有负数）！！！
//dp[i]：从开始位置到i位置最大子段和的值
int main() {
	int n;
	scanf("%d",&n);
	for(int i = 1;i <= n;i++) scanf("%lld",a+i);
	for(int i = 1;i <= n;i++) {
		dp[i] = max(dp[i-1]+a[i],a[i]);
		//当前位置 = max(包括前一位的子段和,只包括自身)
		if(dp[i]>maxx) maxx = dp[i];//取较大值
	}
	printf("%lld",maxx);
	return 0;
}
