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
			sum[i] = sum[i-1]+a[i];//ǰ׺��
		}
		ll ans = -INF,maxx = -INF;//INF���ܹ���
		for(int i = k;i+k <= n;i++) {
			maxx = max(maxx,sum[i]-sum[i-k]);
			//maxxΪi��iǰ�� k���� ���ֵ
			ans = max(ans,maxx+sum[i+k]-sum[i]);
			//ans����Ϊ ǰ�������ȡ��ֵ + ��һ������ �Ľϴ�ֵ
		}
		//ǰ�� + ��1 �ĸ��·�ʽ
		printf("%lld\n",ans);
	}
	return 0;
}
