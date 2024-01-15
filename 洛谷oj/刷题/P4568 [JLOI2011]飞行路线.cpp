// Problem: P4568 [JLOI2011]飞行路线
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P4568
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Author：Lese
// Time：2021-09-15 15:12:28

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

//题解：分层图最短路
//对于分层图来说，其实就是对原来的图，复制n次
//然后对应每个图之间，添加边来连接，并且边权值为0
//因为这样的话，在每个图之间跳的话，花费为0，满足了免费的条件
//由于可以免费k次，那么也就说需要多建k个图，共（k+1)层
//由于免费的次数可以不需要k次，所以需要取所有层的末点（对应终点位置）结果

const int MAXN = 3e5+5;
const int MOD = 1e9+7;
const double pi = acos(double(-1));
struct node{
	int dot,val;
	friend bool operator < (node a,node b) {
		return a.val > b.val;//优先权值小的
	}
};
int n,m,k;
int s,t, dis[MAXN], vis[MAXN];//dis记录距离，vis记录当前点是否松弛
vector<node> g[MAXN];//存边
int dijkstra(int s) {//起点为s
	int endp = (k+1)*n-1;//共k+1层，点数为 n-1 + k*n
	for(int i = 0;i <= endp;i++) dis[i] = INF;//初始化为INF
	priority_queue<node> q;
	q.push({s, 0});//起点
	dis[s] = 0;
	while(!q.empty()) {
		node now = q.top();q.pop();
		if(vis[now.dot]) continue;//已松弛，跳过
		vis[now.dot] = 1;
		for(int i = 0;i < g[now.dot].size();i++) {//遍历所有边
			node tmp = g[now.dot][i];
			if(dis[tmp.dot]>dis[now.dot]+tmp.val) {//可松弛
				dis[tmp.dot] = dis[now.dot] + tmp.val;//更新为较小值
				if(!vis[tmp.dot]) {//还未松弛，入队
					q.push({tmp.dot, dis[tmp.dot]});
				}
			}
		}
	}
	int ans = INF;
	for(int i = 0;i <= k;i++) {//取所有层的结果！！！
		ans = min(ans, dis[t+i*n]);
	}
	return ans;
}
int main() {
	cin>>n>>m>>k;
	cin>>s>>t;
	for(int i = 1;i <= m;i++) {
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v, w});//初始层的边（无向边）
		g[v].push_back({u, w});
		for(int j = 1;j <= k;j++) {//可以免费k次，所以多建k层
			g[u].push_back({v+n, 0});//当前层跳到下一层，费用为0
			g[v].push_back({u+n, 0});
			g[u+n].push_back({v+n, w});//下一层之间移动，费用为w（原费用）
			g[v+n].push_back({u+n, w});
			u += n, v += n;//更新当前层的对应点编号
		}
	}
	cout<<dijkstra(s);
    return 0;
}
