#include<iostream>//ac
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;

//��⣺ѡ��k��Ԫ�أ����㼫��ͣ�ѡ�����������������
//���Եõ�ÿ�β���������ѡ��
//A������ǰλ��Ϊmaxֵ���滻ǰһλ��k+n����
//B���Ե�ǰλΪ��k������ǰ��k-1����Ϊһ�飬�ټ���֮ǰ��dp[i-k]
//dp[i] = min(A, B)

const int MAXN = 3e5+5;
int a[MAXN],dp[MAXN];//dp[i]Ϊiλ���ĵ���Сֵ
int main() {
	int n,k;
	cin>>n>>k;
	for(int i = 1;i <= n;i++) cin>>a[i],dp[i] = INF;
	sort(a+1,a+n+1);//���򣡣���
	dp[k] = a[k]-a[1];//��ʼ����һ��״̬������k�����k��ʼ
	for(int i = k+1;i <= n;i++) {//��k+1��ʼ
		dp[i] = min(dp[i-1]-a[i-1]+a[i],dp[i-k]+a[i]-a[i-k+1]);
	}//AΪһ�飬BΪ����
	cout<<dp[n];
	return 0;
}
