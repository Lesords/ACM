// Problem: Ideal Path
// Contest: Virtual Judge - UVA
// URL: https://vjudge.net/problem/UVA-1599
// Memory Limit: 1024 MB
// Time Limit: 5000 ms
// 
// Author：Lese
// Time：2021-10-24 23:21:58

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

//题解：两次bfs
//倒着做一次bfs，找出从终点开始的所有最短路径
//由于 起点到终点 的最短路径肯定也包括在这些路径里面（距离相等，所以需记录对应距离）
//所以可以从起点开始再bfs，边走边记录对应最小的边权值，选择最小的边权值继续遍历
//记录最小边权值有个小技巧，利用vector存储队列中所有的点
//每次只操作vector里面的点即可
//第一次操作vector计算最小的边权值minn，第二次操作vector来记录所有边权值为minn的点
//注意，最小的边权值可能不止出现一次！！！

const int MAXN = 1e5+5;
const int MOD = 1e9+7;
const double pi = acos(double(-1));
struct node{
	int v,val;
};
vector<node> g[MAXN];		//存边
vector<int> ans;			//记录结果
int dis[MAXN], vis[MAXN];	//dis记录倒着bfs的距离，vis为第二次bfs对应点是否遍历过
int n, m;
void bfs() {//倒着bfs计算从终点到各个点的距离
	queue<int> q;
	q.push(n);
	for(int i = 1;i <= n;i++) dis[i] = -1;		//初始化为-1
	dis[n] = 0;									//终点为0
	while(!q.empty()) {
		int now = q.front();q.pop();
		for(int i = 0;i < g[now].size();i++) {	//遍历所有指向点
			node tmp = g[now][i];
			if(dis[tmp.v]!=-1) continue;		//已遍历，跳过
			dis[tmp.v] = dis[now]+1;			//对应距离+1
			q.push(tmp.v);
		}
	}
}
void bfs2() {
	queue<int> q;
	q.push(1);
	for(int i = 1;i <= n;i++) vis[i] = 0;		//初始化所有点为0
	vis[1] = 1;									//标记起点
	while(!q.empty()) {
		vector<int> dot;
		//存储队列中所有的点用于当前遍历
		while(!q.empty()) dot.push_back(q.front()), q.pop();
		int minn = INF;							//记录最小权值
		for(int i = 0;i < dot.size();i++) {
			int now = dot[i];
			for(auto to:g[now]) {
				if(dis[to.v]!=dis[now]-1) continue;		//如果距离不差1，表示不为最短路，跳过
				minn = min(minn, to.val);		//取最小边权值
			}
		}
		if(minn == INF) return;
		ans.push_back(minn);					//先找最小的边权值，然后再存储所有存在该边权值的指向点
		for(int i = 0;i < dot.size();i++) {
			int now = dot[i];
			for(auto to:g[now]) {
				if(dis[to.v]!=dis[now]-1) continue;		//如果距离不差1，表示不为最短路，跳过
				if(vis[to.v]||to.val!=minn) continue;	//已标记或不为最小边权值，跳过
				vis[to.v] = 1;					//标记对应点
				q.push(to.v);					//记录所有边权值为minn的点
			}
		}
	}
}
int main() {
	fast;
	while(cin >> n >> m) {
		for(int i = 1;i <= n;i++) g[i].clear();	//清空所有边
		for(int i = 1;i <= m;i++) {
			int u, v, val;
			cin >> u >> v >> val;
			g[u].push_back({v, val});			//存边，无向边
			g[v].push_back({u, val});
		}
		bfs();
		ans.clear();							//清空结果
		bfs2();
		cout << ans.size() << "\n";
		for(int i = 0;i < ans.size();i++) {
			if(i) cout << " ";					//注意格式，防止pe
			cout << ans[i];
		}
		cout << "\n";
	}
    return 0;
}
