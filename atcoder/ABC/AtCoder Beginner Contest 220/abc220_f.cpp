// Problem: F - Distance Sums 2
// Contest: AtCoder - AtCoder Beginner Contest 220
// URL: https://atcoder.jp/contests/abc220/tasks/abc220_f
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Author：Lese
// Time：2021-09-26 20:00:27

#include<iostream>//ac
#include<cstring>
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
using namespace std;
const int MAXN = 2e5+5;
const int MOD = 1e9+7;
const double pi = acos(double(-1));
vector<int> g[MAXN];
int n;
int dep[MAXN], son[MAXN];
ll num[MAXN];//爆int！！！
void dfs(int now, int fa) {
	son[now] = 1;
	for(int i = 0;i < g[now].size();i++) {
		int dot = g[now][i];
		if(dot == fa) continue;
		dep[dot] = dep[now]+1;
		dfs(dot, now);
		son[now] += son[dot];
	}
	num[1] += dep[now];
}
void dfs1(int now,int fa) {
	for(int i = 0;i < g[now].size();i++) {
		int dot = g[now][i];
		if(dot == fa) continue;
		num[dot] = num[now]-son[dot] + (n-son[dot]);
		dfs1(dot, now);
	}
}
int main() {
	cin>>n;
	for(int i = 1;i < n;i++) {
		int u, v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, -1);	
	dfs1(1, -1);
	for(int i = 1;i <= n;i++) {
		cout<<num[i]<<"\n";
	}
    return 0;
}
