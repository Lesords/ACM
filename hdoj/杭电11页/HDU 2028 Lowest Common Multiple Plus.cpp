#include<iostream>
#define ll long long
using namespace std;
ll gcd(ll x,ll y) {
	return x%y==0?y:gcd(y,x%y);
}
ll lcm(ll x,ll y) {
	return x*y/gcd(x,y);
}
int main() {
	ll n,a;
	cout<<gcd(25,15)<<endl;
	while(cin>>n) {
		ll m,cnt=1;
		for(ll i=1;i<=n;i++) {
			cin>>a;
			cnt=lcm(cnt,a);
		}
		cout<<cnt<<endl;
	}
	return 0;
}
