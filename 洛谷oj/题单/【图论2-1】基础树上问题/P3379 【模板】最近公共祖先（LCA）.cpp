// Problem: P3379 【模板】最近公共祖先（LCA）
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3379
// Memory Limit: 500 MB
// Time Limit: 1500 ms
// 
// Author：Lese
// Time：2021-09-14 23:38:18

#include<iostream>//ac
#include<cmath>
#include<vector>
#include<queue>
#include<algorithm>
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
using namespace std;
const int MAXN = 5e5+5;
vector<int> g[MAXN];
int dep[MAXN], f[MAXN][20];
int n, m, s, siz;
void bfs(int s) {//s为根节点
	siz = (int)(log(n)/log(2)) + 1;
	queue<int> q;
	q.push(s);
	dep[s] = 1;
	while(!q.empty()) {
		int x = q.front();q.pop();
		for(int i = 0;i < g[x].size();i++) {
			int dot = g[x][i];
			if(dep[dot]) continue;
			dep[dot] = dep[x] + 1;
			f[dot][0] = x;
			for(int j = 1;j <= siz;j++)
				f[dot][j] = f[f[dot][j-1]][j-1];
			q.push(dot);
		}
	}
}
int lca(int x, int y) {
	if(dep[x] > dep[y]) swap(x, y);//让y为深度最大的点，使y向上寻找
	for(int i = siz;i >= 0;i--)
		if(dep[f[y][i]] >= dep[x]) y = f[y][i];
	if(x == y) return x;
	for(int i = siz;i >= 0;i--) 
		if(f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
	return f[x][0];//父节点即为LCA
}
int main() {
	fast;
	cin>>n>>m>>s;
	for(int i = 1;i <= n-1;i++) {
		int u, v;
		cin>>u>>v;
		g[u].push_back(v);//存边
		g[v].push_back(u);
	}
	bfs(s);//预处理
	for(int i = 1;i <= m;i++) {
		int a,b;
		cin>>a>>b;
		cout<<lca(a,b)<<"\n";
	}
    return 0;
}
