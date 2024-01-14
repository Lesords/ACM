#include<iostream>//ac
#define ll long long 
using namespace std;
ll gcd(ll a,ll b) {
	return a%b==0?b:gcd(b,a%b);
}
ll lcm(ll a,ll b) {
	return a*b/gcd(a,b);
}
int main() {
	ll a,b;
	cin>>a>>b;
	cout<<lcm(a,b)<<endl;
	return 0;
}
