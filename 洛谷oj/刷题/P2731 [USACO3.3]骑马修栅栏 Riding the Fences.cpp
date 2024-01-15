// Problem: P2731 [USACO3.3]骑马修栅栏 Riding the Fences
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2731
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Author：Lese
// Time：2021-09-19 10:07:09

#include<iostream>//ac
#include<stack>
#include<vector>
#include<queue>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;
const int MAXN = 1030;
int in[MAXN], g[MAXN][MAXN];
vector<int> ans;
int m, minn = INF,maxx;
void dfs(int now) {
	for(int i = minn;i <= maxx;i++) {
		if(g[now][i]) {
			g[i][now]--;
			g[now][i]--;
			dfs(i);
		}
	}
	ans.push_back(now);
}
int main() {
	cin>>m;
	for(int i = 1;i <= m;i++) {
		int u,v;
		cin>>u>>v;
		minn = min(minn, u);
		minn = min(minn, v);
		maxx = max(maxx, u);
		maxx = max(maxx, v);
		g[u][v]++;
		g[v][u]++;
		in[u]++;
		in[v]++;
	}
	int cnt = 0, s,flag = INF;
	s = minn;
	for(int i = minn;i <= maxx;i++) {
		if(in[i]&1) cnt++,flag = min(flag, i);
	}//起点取较小值
	if(cnt==2) s = flag;
	dfs(s);
	while(ans.size()) cout<<ans.back()<<"\n", ans.pop_back();
	return 0;
}