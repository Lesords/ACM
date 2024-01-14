// Problem: B - Pizza
// Contest: AtCoder - Monoxer Programming Contest 2022（AtCoder Beginner Contest 238）
// URL: https://atcoder.jp/contests/abc238/tasks/abc238_b
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Author：Lese
// Time：2022-02-05 20:08:20

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
int deg[380];
int main() {
	int n;
	cin >> n;
	deg[0] = 1;
	int cur = 0, tmp;
	for(int i = 1;i <= n;i++) {
		cin >> tmp;
		cur += tmp;
		if(cur >= 360) cur -= 360;
		deg[cur] = 1;
	}
	vector<int> val;
	int ans = 0;
	for(int i = 1;i <= 2;i++) {
		for(int j = 0;j < 360;j++) if(deg[j]) val.push_back(j);
	}
	for(int i = 1;i < val.size();i++) {
		if(val[i] > val[i-1]) ans = max(ans, val[i] - val[i-1]);
		else {
			ans = max(ans, 360-val[i-1] + val[i]);	
		}
	}
	cout << ans;
    return 0;
}
