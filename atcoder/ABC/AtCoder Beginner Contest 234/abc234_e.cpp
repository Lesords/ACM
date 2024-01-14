// Problem: E - Arithmetic Number
// Contest: AtCoder - AtCoder Beginner Contest 234
// URL: https://atcoder.jp/contests/abc234/tasks/abc234_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Author：Lese
// Time：2022-01-08 20:27:05

#include<iostream>//ac
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<sstream>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<utility>
#include<bitset>
#include<algorithm>
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define pii pair<int,int>
#define fi first
#define se second
#define eps 1e-6
#define lson rt<<1
#define rson rt<<1|1
using namespace std;
const int MAXN = 2e5+5;
const int MOD = 1e9+7;
const double pi = acos(double(-1));
vector<int> val;
int siz;
bool judge(ll x) {
	if(x < 10) return true;
	while(x) {
		val.push_back(x%10);
		x /= 10;
	}
	siz = val.size();
	int dis = val[1] - val[0];
	for(int i = 1;i < val.size();i++) {
		if(val[i] - val[i-1] != dis) return false;
	}
	return true;
}
ll solve(int a, int b, int siz) {
	ll ans = a;
	for(int i = 1;i <= siz-1;i++) {
		a += b;
		if(a >= 10 || a < 0) return -1;
		ans = ans * 10 + a;
	}
	return ans;
}
int main() {
	ll x;
	cin >> x;
	if(judge(x)) {
		cout << x << '\n';
	}
	else {
		reverse(val.begin(), val.end());
		ll ans = 0;
		if(val[0] < 9) ans = solve(val[0] + 1, 0, siz);
		else ans = solve(1, 0, siz+1);
		ll tmp;
		for(int i = -9;i <= 9;i++) {
			tmp = solve(val[0], i, siz);
			if(tmp!=-1 && tmp >= x) ans = min(ans, tmp);
		}
		if(val[0] < 9) {
			for(int i = -9;i <= 9;i++) {
				tmp = solve(val[0] + 1, i, siz);
				if(tmp != -1 && tmp >= x) ans = min(ans, tmp);
			}	
		}
		cout << ans;
	}
    return 0;
}
