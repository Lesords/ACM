#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;
int main() {
	ll a,b,c,x,y,z;
	cin>>a>>b>>c>>x>>y>>z;
	ll ans = min(a,y)+min(b,z)+min(c,x);
	cout<<ans;
	return 0;
}
