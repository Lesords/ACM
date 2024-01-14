#include<iostream>//ac
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<utility>
#include<algorithm>
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

//题意：求非指定起点的第k小路径值
//题解：首先将每个点的所有出边按照边权值从小到大排序
//可以先将所有起点的最短路径放入优先队列中
//优先队列需要维护：起点、终点、总边权值、起点访问的第几个出边
//每次选择队列中总边权值最小的点
//1. 判断起点是否除了当前出边还有别的出边可以走，如果有，则走向那个点
//（也就是说，当前位置回退然后走另外一条边）
//注意更新编号信息，以及总边权值需要删除当前边权值然后再更新
//2. 接着判断当前终点是否有出边，有则继续走，注意更新对应信息

const int MAXN = 5e4+5;
const int MOD = 1e9+7;
struct node{
	int u,v;
	ll w;
	int cur;//cur为当前走过的边编号
	friend bool operator < (node a,node b) {
		return a.w > b.w;//优先队列，优先边权值小的
	}	
};
struct edge{
	int v;
	ll w;
	friend bool operator < (edge a,edge b) {
		return a.w < b.w;//权值从小到大排序
	}
};
vector<edge> g[MAXN];//记录对应边及边权值
ll ans[MAXN];//记录最后结果
int n,m,q;
void solve() {
	priority_queue<node> que;
	for(int i = 1;i <= n;i++) {//将所有起点的最短距离的边入队列
		if(!g[i].empty()) {
			edge tmp = g[i][0];
			node now = {i, tmp.v, tmp.w, 0};//当前走的是0边
			que.push(now);
		}
	}
	for(int i = 1;i < MAXN;i++) {//最多只有5e5次，所以提前全部计算即可
		node tmp = que.top();
		que.pop();
		ans[i] = tmp.w;//当前点的总边权值即为对应大小的值
		if(tmp.cur+1<g[tmp.u].size()) {//起点tmp.u还有其他出边可走
			edge to = g[tmp.u][tmp.cur+1];//起点tmp.u的下一条边
			//注意边权值需 减去上次的，然后再加上这次的边权值，更新对应编号
			node now = {tmp.u, to.v, tmp.w-g[tmp.u][tmp.cur].w+to.w, tmp.cur+1};
			que.push(now);
		}
		if(!g[tmp.v].empty()) {//终点有出边可走
			edge to = g[tmp.v][0];
			node now = {tmp.v, to.v, tmp.w+to.w, 0};//先走0号边
			que.push(now);
		}
	}
}
int main() {
	fast;
	int t;
	cin>>t;
	while(t--) {
		cin>>n>>m>>q;
		for(int i = 1;i <= n;i++) g[i].clear();//清空所有边的信息
		for(int i = 1;i <= m;i++) {
			int u,v,w;
			cin>>u>>v>>w;
			edge e = {v,w};
			g[u].push_back(e);//存边
		}
		for(int i = 1;i <= n;i++) {//排序所有边
			sort(g[i].begin(), g[i].end());
		}
		solve();
		for(int i = 1;i <= q;i++) {//直接输出结果
			int tmp;
			cin>>tmp;
			cout<<ans[tmp]<<"\n";
		}		
	}
    return 0;
}