#include<cstdio>//ac
#include<algorithm>
#define INF 0x7f3f3f3f
//INF�����󣡣���
#define ll long long
using namespace std;
const int MAXN = 2e5+5;
ll dp[MAXN][2];
//dp[i][0]:iλ���� û�� ��1����С�ܴ���
//dp[i][1]:iλ���� �� ��1����С�ܴ���

int a[MAXN],b[MAXN];
int main() {
	int n;
	scanf("%d",&n);
	for(int i = 1;i <= n;i++) {
		scanf("%d%d",&a[i],&b[i]);
		dp[i][0] = dp[i][1] = INF;//��ʼ��ΪINF
		//dp��Ҫ����С�ܴ��ۣ�������Ҫ��ʼ��ΪINF
	}
	dp[1][1] = b[1],dp[1][0] = 0;//��ʼ����һ��״̬
	//��1�Ͳ���1��ֵ
	for(int i = 2;i <= n;i++) {
		//�ж��ܹ���4�����
		//��ǰ����1��ǰ��1��ǰ����1
		//��ǰ��1  ��ǰ����1��ǰ��1
		if(a[i]!=a[i-1]) dp[i][0] = min(dp[i][0],dp[i-1][0]);
		if(a[i]!=a[i-1]+1) dp[i][0] = min(dp[i][0],dp[i-1][1]);
		if(a[i]+1!=a[i-1]) dp[i][1] = min(dp[i][1],dp[i-1][0]+b[i]);
		if(a[i]+1!=a[i-1]+1) dp[i][1] = min(dp[i][1],dp[i-1][1]+b[i]);
		//��ǰ��1ʱ��Ҫ���϶�Ӧ�Ĵ��� b[i]
	}
	printf("%lld",min(dp[n][1],dp[n][0]));
	return 0;
}
