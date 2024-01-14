// Problem: C - Martial artist
// Contest: AtCoder - AtCoder Beginner Contest 226
// URL: https://atcoder.jp/contests/abc226/tasks/abc226_c
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Author：Lese
// Time：2021-11-07 20:02:54

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

//题解：由于每次只能学习一个动作，那么其实可以先dfs出所有需要学习的动作
//然后再逐个累加结果即可

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
const double pi = acos(double(-1));
vector<int> g[MAXN];
ll tim[MAXN];
int vis[MAXN];//vis表示当前动作是否需要学习
void dfs(int pos) {
	for(int i = 0;i < g[pos].size();i++) {
		int now = g[pos][i];
		if(vis[now]) continue;//已记录，跳过
		vis[now] = 1;//记录当前位置
		dfs(now);
	}
	return ;
}
bool cmp(int a, int b) {
	return a < b;
}
int main() {
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++) {
		cin >> tim[i];
		int num, tmp;
		cin >> num;
		for(int j = 1;j <= num;j++) {
			cin >> tmp;
			g[i].push_back(tmp);
		}
	}
	for(int i = 1;i <= n;i++) sort(g[i].begin(), g[i].end(), cmp);
	ll ans = tim[n];//不标记最后一个，所以初始化最后一个
	for(int i = 0;i < g[n].size();i++) {
		int pos = g[n][i];
		if(vis[pos]) continue;//已标记，跳过
		vis[pos] = 1;
		dfs(pos);
	}
	// 累加所有需要学习的动作
	for(int i = 1;i <= n;i++) if(vis[i]) ans += tim[i];
	cout << ans << "\n";
    return 0;
}
