#include<iostream>//ac �������
#include<algorithm>
#define ll long long
using namespace std;

//���Ϊ��ǰֵ - ǰһ��ֵ
//ά����ʱ���ж�λ�ü���
//ȡֵ��ʱ��Ϊ ��ǰֵ = ǰһ��ֵ+���

//Ҳ����˵��־���ǰ���������Ĳ�ֵ

const int MAXN = 2e5+5;
ll a[MAXN];
int main() {
	int n,m,l,r;
	ll ans = 0;
	cin>>n>>m;
	while(m--) {
		cin>>l>>r;
		a[l]++,a[r+1]--;//�޸Ĳ��
	}
	//ȡֵ
	for(int i = 1;i <= n;i++) a[i] += a[i-1];
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++) ans += a[i]*i;
	cout<<ans;
	return 0;
}
