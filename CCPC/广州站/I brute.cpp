#include<iostream>
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

//题解：暴力
const int MAXN = 2e5+5;
const int MOD = 998244353;
int a[MAXN];
ll cal(int val) {
	ll ans = 1;
	for(int i = 1;i <= val;i++) {
		ans *= val;
	}
	return ans;
}
int main() {
	for(int i = 1;i <= 11;i++) {
		ll ans = 0;
		for(int j = 1;j <= i;j++) a[j] = j;
		do {
			ll sum  = 0;
			// for(int j = 1;j <= i;j++) cout << a[j] << " ";
			// cout << "\n";
			bool ok = 1;
			for(int j = 1;j <= i;j++) {
				sum += 2*a[j];
				if(sum%j) {
					ok = 0;
					break;
				}
			}
			ans += ok;
		}while(next_permutation(a+1, a+i+1));
		cout << i << " "<< ans << " "<< cal(i) << "\n";
	}
	return 0;
}