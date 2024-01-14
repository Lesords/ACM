#include<iostream>//ac
#define ll long long
using namespace std;
ll gcd(ll a,ll b) {//最大公因数
	return a%b==0?b:gcd(b,a%b);
}
ll lcm(ll a,ll b) {//最小公倍数
	return a*b/gcd(a,b);
}
int main() {
	int t,n;
	cin>>t;
	while(t--) {
		cin>>n;
		ll ans = 1,tmp;//初始化为1
		while(n--) {
			cin>>tmp;
			ans = lcm(tmp,ans);
		}
		cout<<ans<<endl;
	}
	return 0;
}
