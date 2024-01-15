#include<iostream>//ac
#define ll long long
using namespace std;
const int MOD = 1e9+7;
const int MAXN = 2050;
ll p[MAXN],dp[MAXN][MAXN];//�ᱬint����Ҫll
//dp[i][j] ����i���д��j��ĸ���
//i���д��j�� = (i-1)���д��j����i����� + (i-1)���д��(j-1)����i�����
//�� dp[i][j] = dp[i-1][j]*(MOD+1-p[i]) + dp[i-1][j-1]*p[i]

//(a/b)%MOD = p[i] => b*p[i]%MOD = a
//��bΪ1(aΪ����ֵ)������ p[i] = a + MOD => a = p[i] - MOD
//�����ʣ�1-a = 1+MOD-p[i]

//Ҳ�ɰ�(a/b)����һ������(����ֵ)������ p[i]%MOD = a/b
//=> p[i] = a/b + MOD  =>  a/b = p[i] - MOD

//������� ��ȷ���� = ģ��ֵ(p[i]) - ģ(MOD)
//��i�����ȷ��Ϊ p[i],������Ϊ (MOD+1-p[i])

int main() {
	int n;
	cin>>n;
	for(int i = 1;i <= n;i++) cin>>p[i];
	dp[0][0] = 1;//0���д��0��Ϊ1��������Ϊ0
	for(int i = 1;i <= n;i++) {
		dp[i][0] = dp[i-1][0]*(MOD+1-p[i])%MOD;//�ȳ�ʼ��0��
		for(int j = 1;j <= i;j++) {//Ȼ�����ʣ�������
			dp[i][j] = dp[i-1][j]*(MOD+1-p[i])%MOD + dp[i-1][j-1]*(p[i]%MOD);
			dp[i][j] %= MOD;
		}
	}
	for(int i = 0;i <= n;i++) {
		if(i!=0) cout<<' ';
		cout<<dp[n][i];
	}
	return 0;
}
