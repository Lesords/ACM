#include<iostream>//ac
#include<cstdio>
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int MAXN = 2e5+5;
ll a[MAXN],dp[MAXN],maxx = -INF;//��Ϊ��ֵ���и�����������
//dp[i]���ӿ�ʼλ�õ�iλ������Ӷκ͵�ֵ
int main() {
	int n;
	scanf("%d",&n);
	for(int i = 1;i <= n;i++) scanf("%lld",a+i);
	for(int i = 1;i <= n;i++) {
		dp[i] = max(dp[i-1]+a[i],a[i]);
		//��ǰλ�� = max(����ǰһλ���Ӷκ�,ֻ��������)
		if(dp[i]>maxx) maxx = dp[i];//ȡ�ϴ�ֵ
	}
	printf("%lld",maxx);
	return 0;
}
