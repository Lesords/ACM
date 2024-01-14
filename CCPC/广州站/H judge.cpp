#include<iostream>//
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
#include<algorithm>
#define ll long long
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
const int MAXN = 2e5+5;
const int MOD = 998244353;
const int  N = 100;
bool judge(ll a, ll b, ll c, ll x, ll y, ll z) {
	if(x%y==a&&y%z==b&&z%x==c) return true;
	return false;
}
void cal(ll a, ll b, ll c) {
	ll x, y, z;
	if(a==b&&b==c) {
		return;
	}
	if(a>=b&&a>=c) {
		x = a;
		z = c+x;
		y = ((x/z)+1) * z + b;
	}
	if(judge(a, b, c, x, y, z)) {
		// cout << x << " "<< y << " " << z << "\n";
		return ;
	}
	if(b >= a && b >= c) {
		y = b;
		x = a+b;
		z = ((y/x)+1) * x + c;
	}
	if(judge(a, b, c, x, y, z)) {
		// cout << x << " "<< y << " " << z << "\n";
		return ;
	}
	if(c >= a && c >= b) {
		z = c;
		y = z+b;
		x = a + ((z/y)+1)*y;
	}
	if(judge(a, b, c, x, y, z)) {
		// cout << x << " "<< y << " " << z << "\n";
		return ;
	}
	
	if(x%y==a&&y%z==b&&z%x==c) ;
	else {
		cout <<"------\n";
		cout << a << " " << b << " " << c << "\n";
		cout << x << " " << y << " " << z << "\n";
		cout << "WA here \n";
		cout <<"------\n";
	}
}
int main() {
	int t;
	// cin >> t;
	// while(t--) {
		ll a, b, c;
		for(int i = 0;i <= N;i++) {
			for(int j = 0;j <= N;j++) {
				for(int k = 0;k <= N;k++) {
					cal(i*1ll, j*1ll, k*1ll);
				}
			}
		}
	// }
	return 0;
}