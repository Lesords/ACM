#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;
const int MAXN = 2e5+5;
ll a[MAXN];//��ֵ����int
int main() {
	ll n,m,sum = 0;
	cin>>n>>m;
	for(int i = 1;i <= n+m+1;i++) cin>>a[i],sum += a[i];
	if(m==0) {//ֻ�мӷ�����ֱ������ܺͼ���
		cout<<sum<<endl;
		return 0;
	}
	sort(a+1,a+n+m+2);//��С��������
	//ʣ�����������ȫ������ȫ�Ǹ���������+�Ǹ���
	if(a[1]<=0&&a[n+1+m]>=0) {//���зǸ���Ҳ�з�����
		ll ans = 0;//ֻ���и��ž���תΪ��
		for(int i = 1;i <= n+m+1;i++) ans += abs(a[i]);
		cout<<ans<<endl;
		return 0;
	}
	else if(a[1]<0&&a[n+1+m]<0) {//ֻ�и���
		ll ans = a[n+1+m];//������ֵ��С�ķ��ڵ�һλ��ʣ����ܻ����
		//�ӷ������ĸ������������ڣ�����������ֱ�Ӳ�����Ϊ��
		for(int i = 1;i <= n+m;i++) ans += abs(a[i]);
		cout<<ans<<endl;
		return 0;
	}
	ll ans = a[n+1+m];//ֻ�зǸ�����
	for(int i = 1;i <= m;i++) ans -= a[i];//��С��
	for(int i = m+1;i <= n+m;i++) ans += a[i];//�Ӵ��
	cout<<ans<<endl;
	return 0;
}
