#include<iostream>//ac
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

bool judge(ll a, ll b, ll c, ll x, ll y, ll z) {
	if(x%y==a&&y%z==b&&z%x==c) return true;
	return false;
}

int main() {
	int t;
	cin >> t;
	for(int cas = 1;cas <= t;cas++) {
		ll a, b, c;
		ll x, y, z;
		cin >> a >> b >> c;
		if(a==b&&b==c) {
			if(!a) cout << "YES\n1 1 1\n";
			else {
				cout << "NO\n";
			}
			continue;
		}
		cout <<"YES\n";
		if(a>=b&&a>=c) {
			x = a;
			z = c+x*2;
			y = ((x/z)+1) * z + b;
			if(judge(a, b, c, x, y, z)) {
				cout << x << " "<< y << " " << z;
				// if(cas!=t) cout << "\n";
				
				cout << "\n";
				continue;
			}
		}
		
		if(b >= a && b >= c) {
			y = b;
			x = a+y*2;
			z = ((y/x)+1) * x + c;
			cerr << "b:" << x << " " << y << " "<< z << "\n";
			if(judge(a, b, c, x, y, z)) {
				cout << x << " "<< y << " " << z;
				// if(cas!=t) cout << "\n";
				
				cout << "\n";
				continue;
			}
		}
		
		if(c >= a && c >= b) {
			z = c;
			y = z*2+b;
			x = a + ((z/y)+1)*y;
			if(judge(a, b, c, x, y, z)) {
				cout << x << " "<< y << " " << z;
			// if(cas!=t) cout << "\n";
				cout << "\n";
			}
		}
	}
	return 0;
}