#include<iostream>//ac ǰ׺��
#include<cstdio>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;

//��⣺��һ������ǰ�ƶ�kλʱ
//ֵ = ��ʼ�ܺͿ۳�a[i]*k�ټ��� ǰһλ��ǰkλ�������
//��k+1��n֮�俪ʼ��ѯ���޸����ֵ

const int MAXN = 1e5+5;
ll a[MAXN],sum[MAXN],n,k;
int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		ll tot = 0,ans = 0;//��ʼ��Ϊ0
		scanf("%lld%lld",&n,&k);
		for(ll i = 1;i <= n;i++) {
			scanf("%lld",&a[i]),tot += a[i]*i;//tot�ܺ�
			sum[i] = (i>1?sum[i-1]:0) + a[i];//ǰ׺��
		}
		for(int i = k+1;i <= n;i++) {
			ll tmp = tot-a[i]*k+(sum[i-1]-sum[i-1-k]);
			ans = max(ans,tmp);//�������ֵ
		}
		printf("%lld\n",ans);
	}
	return 0;
}
