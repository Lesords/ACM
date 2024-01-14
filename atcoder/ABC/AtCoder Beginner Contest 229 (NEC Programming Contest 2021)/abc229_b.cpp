// Problem: B - Hard Calculation
// Contest: AtCoder - NEC Programming Contest 2021(AtCoder Beginner Contest 229)
// URL: https://atcoder.jp/contests/abc229/tasks/abc229_b
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Author：Lese
// Time：2021-11-27 20:11:10

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
int solve(ll val) {
	int cnt = 0;
	while(val) {
		
	}
	return cnt;
}
int main() {
	ll a, b;
	cin >> a >> b;
	bool ok = 0;
	while(a&&b) {
		if(a%10+b%10>=10) {
			ok = 1;break;
		}
		a /= 10, b /= 10;
	}
	if(ok) cout << "Hard";
	else cout << "Easy";
    return 0;
}
