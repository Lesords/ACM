#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;
ll multi(ll a,ll b,ll p) {//���ٳ�
	ll ans = 0,bas = a;
	while(b) {//b��a���
		if(b&1) ans = (ans+bas)%p;
		bas = (bas+bas)%p;
		b >>= 1;
	}
	return ans;
}
ll poww(ll a,ll b,ll p) {//������
	ll ans = 1,bas = a;
	while(b) {//b��a���
		if(b&1) ans = multi(ans,bas,p);
		bas = multi(bas,bas,p);
		b >>= 1;
	}
	return ans;
}
int main() {
	int t;
	ll a,b,p;
	cin>>t;
	while(t--) {
		cin>>a>>b>>p;
		cout<<poww(a,b,p)<<'\n';
	}
	return 0;
}
