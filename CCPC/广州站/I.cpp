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
ll poww(ll a, ll b) {
	ll ans = 1;
	while(b) {
		if(b&1) ans = (ans*a)%MOD;
		a = (a*a)%MOD;
		b >>= 1;
	}
	return ans%MOD;
}
int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		if(n == 1) cout << "1\n";
		else if(n==2) cout << "2\n";
		else if(n==3) cout << "6\n";
		else {
			cout << (6*poww(2, n-3)%MOD) << "\n";
		}
	}
	return 0;
}