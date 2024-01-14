// Problem: E - Destruction
// Contest: AtCoder - AtCoder Beginner Contest 218
// URL: https://atcoder.jp/contests/abc218/tasks/abc218_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Author：Lese
// Time：2021-09-11 20:55:47

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
struct node{
	int u,v;
	ll w;
	friend bool operator < (node a,node b) {
		return a.w < b.w;
	}
}g[MAXN];
int vis[MAXN],dis[MAXN];
int getf(int pos) {
	return dis[pos]==pos?pos:dis[pos] = getf(dis[pos]);
}
int main() {
	int n,m;
	cin>>n>>m;
	for(int i = 1;i <= n;i++) dis[i] = i;
	for(int i = 1;i <= m;i++) {
		int a,b;
		ll c;
		cin>>a>>b>>c;
		g[i] = {a, b, c};
	}
	sort(g+1, g+m+1);//m条边！！！
	ll ans = 0;
	//先选出所有的最小生成树的边，然后剩余的边可以删除
	//注意：负边贡献为负数，所以可以不移出（不移出就没有贡献）
	for(int i = 1;i <= m;i++) {
		node now = g[i];
		if(getf(now.u)!=getf(now.v)) {
			vis[i] = 1;
			now.u = getf(now.u);
			now.v = getf(now.v);
			dis[now.u] = now.v;
		}
		else {
			ans += max(0ll, now.w);
		}
	}
	cout<<ans<<"\n";
    return 0;
}
