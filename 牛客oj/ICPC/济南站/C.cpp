// Problem: Stone Game
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/23862/C
// Memory Limit: 524288 MB
// Time Limit: 2000 ms
// 
// Author：Lese
// Time：2021-11-11 18:33:35

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
ll a[5];
int main() {
	for(int i = 1;i <= 3;i++) cin >> a[i];
	ll ans = 0;
	if(a[1] >= a[2]) {
		ans += a[2] * 2;
		a[1] -= a[2];
		ans += 3 * (a[1]/3);
		if(a[1]%3==2) {
			ans += 1;
		}
	}
	else {
		ans += a[1] * 2;
		a[2] -= a[1];
		ans += 6 * (a[2]/3);
		if(a[2]%3==2) {
			ans += 4;
		}
	}
	cout << ans;
    return 0;
}
