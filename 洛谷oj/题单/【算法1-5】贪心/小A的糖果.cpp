#include<iostream>//ac
#define ll long long
using namespace std;
const int MAXN = 2e5 + 5;
ll a[MAXN];
int main() {
	ll n,x,ans = 0,tmp;//��Ҫll ������
	cin>>n>>x;
	for(int i = 1;i <= n;i++) {
		cin>>a[i];
		if(a[i]>x) {//������������x
			ans += a[i]-x;
			a[i] = x;
		}
	}//��ǰλ + ǰһλ �ж��ǹ������������ظ�
	for(int i = 2;i <= n;i++) {//��2��ʼ������
		if(a[i]+a[i-1]>x) {
			tmp = a[i]+a[i-1]-x;
			ans += tmp;
			a[i] -= tmp;
		}
	}
	cout<<ans<<endl;
	return 0;
}
