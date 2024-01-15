#include<iostream>//ac
#include<cmath>
#define ll long long
using namespace std;
ll poww(ll a,ll b) {
	ll ans = 1,base = a;
	while(b) {
		if(b&1) ans *= base;
		base *= base;
		b >>= 1;
	}
	return ans;
}
int main() {
	int t;cin>>t;
	ll a,b,c,d,e,f,g;
	while(t--) {
		cin>>a>>b>>c>>d>>e>>f>>g;
		ll A = pow(a,d);
		ll B = pow(b,e);
		ll C = pow(c,f);
		cout<<(A+B+C==g?"Yes":"No")<<endl;
	}
	return 0;
}
