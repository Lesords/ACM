// Problem: A - First Grid
// Contest: AtCoder - NEC Programming Contest 2021(AtCoder Beginner Contest 229)
// URL: https://atcoder.jp/contests/abc229/tasks/abc229_a
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Author：Lese
// Time：2021-11-27 20:00:41

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
char a[5][5];
int vis[5][5];
int nextt[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
void dfs(int x,int y) {
	for(int i = 0;i < 4;i++) {
		int tx = x+nextt[i][0];
		int ty = y+nextt[i][1];
		if(tx <= 0||ty <= 0||tx >= 3 || ty >= 3) continue;
		if(vis[tx][ty]||a[tx][ty]=='.') continue;
		vis[tx][ty] = 1;
		dfs(tx, ty);
	}
}
int main() {
	bool ok = true;
	for(int i = 1;i <= 2;i++) {
		for(int j = 1;j <= 2;j++) {
			cin >> a[i][j];
		}
	}
	int cnt = 0;
	for(int i = 1;i <= 2;i++) {
		for(int j = 1;j <= 2;j++) {
			if(a[i][j]=='.') continue;
			if(vis[i][j]) continue;
			cnt++;
			vis[i][j] = 1;
			dfs(i, j);
			if(cnt>1) ok = false;
		}
	}
	if(ok) cout << "Yes";
	else cout << "No";
    return 0;
}
