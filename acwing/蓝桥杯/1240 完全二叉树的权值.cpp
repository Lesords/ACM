#include<iostream>//ac
#include<algorithm>
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;

//��⣺ǰ׺�ͼ���ÿ����ȵ�����ͣ���������ֵ

const int MAXN = 1e5+5;
ll a[MAXN],sum[MAXN];
int main() {
	int n;
	cin>>n;
	ll ans = -INF,deep = 0,cnt = 1;//ans��ʼ��Ϊ���������
	for(int i = 1;i <= n;i++) cin>>a[i],sum[i] = sum[i-1]+a[i];
	for(int i = 1;i <= n;i *= 2) {//�����������
		ll tmp;
		if(i*2-1>n) tmp = sum[n]-sum[i-1];//���һ��û��
		else tmp = sum[i*2-1]-sum[i-1];
		if(tmp>ans) {//��ǰ��ȵ�����͸���ʱ���½��
			ans = tmp;
			deep = cnt;
		}
		cnt++;//��ǰ���++
	}
	cout<<deep<<endl;
	return 0;
}
