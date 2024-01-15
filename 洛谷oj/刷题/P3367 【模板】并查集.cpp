// Problem: P3367 【模板】并查集
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3367
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Author：Lese
// Time：2021-09-14 10:10:29

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
int dis[MAXN];
void init(int n) {
	for(int i = 1;i <= n;i++) dis[i] = i;
}
int getf(int pos) {
	return dis[pos]==pos?pos:dis[pos] = getf(dis[pos]);
}
void Merge(int u,int v) {
	u = getf(u), v = getf(v);
	if(u==v) return;
	dis[v] = u;
}
int main() {
	int n, m;
	cin>>n>>m;
	init(n);
	for(int i = 1;i <= m;i++) {
		int op, u, v;
		cin>>op>>u>>v;
		if(op==1) {
			Merge(u, v);
		}
		else {
			if(getf(u)==getf(v)) cout<<"Y\n";
			else cout<<"N\n";
		}
	}
    return 0;
}
