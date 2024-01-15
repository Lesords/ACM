// Problem: Fight against involution
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/23862/D
// Memory Limit: 524288 MB
// Time Limit: 2000 ms
// 
// Author：Lese
// Time：2021-11-11 19:40:38

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
struct node{
	ll x, y;
	friend bool operator < (node a, node b) {
		//先按照上限从小到大排序
		//如果上限相等，那么按照下限从大到小排序
		
		//因为上限相等的情况下，对应的最后结果也需要相等
		//那么肯定只能取其中下限最大的值（下限最大才能满足其他上限相等的情况）
		//例如
		// 1 3
		// 2 3
		// 3 3 ,该例子中满足条件的值为3（而不是1）
		if(a.y == b.y) return a.x > b.x;
		return a.y < b.y;
	}
}a[MAXN];
int main() {
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++) {
		cin >> a[i].x >> a[i].y;
	}
	sort(a+1, a+n+1);
	ll ans = a[1].x, now = a[1].x;//now记录满足条件的值
	for(int i = 2;i <= n;i++) {
		//大于当前下限的值，则直接取now，否则更新now为对应下限的值
		if(now >= a[i].x) {
			ans += now;
		}
		else {
			now = a[i].x;
			ans += now;
		}
	}
	cout << ans;
    return 0;
}

/*
?
2
1 3
1 4
*/