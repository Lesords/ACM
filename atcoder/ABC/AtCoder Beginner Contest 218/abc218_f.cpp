// Problem: F - Blocked Roads
// Contest: AtCoder - AtCoder Beginner Contest 218
// URL: https://atcoder.jp/contests/abc218/tasks/abc218_f
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Author：Lese
// Time：2021-09-13 08:53:17

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

//题解：bfs求最短路径
//首先在没有限制的情况下跑一次bfs，记录路径中的边
//然后接下来遍历所有的边，判断这条边是否被记录（在不限制边的最短路径中）
//如果这条边在 最短路径 中，则需要重新bfs计算
//否则表示这条边对结果无影响，直接输出原结果即可

const int MAXN = 405;
const int MOD = 1e9+7;
const double pi = acos(double(-1));
struct node {
	int dot, index;
};
vector<node> g[MAXN];//存边，注意题目中是单向边！！！
node from[MAXN];//记录最短路径（上一个节点的标号以及边的下标）
int n, m;
int vis[MAXN*MAXN],dis[MAXN];//vis记录当前边是否删除，dis记录最短路径
void bfs(bool sav) {//sav表示是否需要记录最短路径
	queue<int> q;
	for(int i = 1;i <= n;i++) dis[i] = -1;//初始为-1，表示不可到达
	dis[1] = 0;//起点为0
	q.push(1);
	while(!q.empty()) {
		int now = q.front();
		q.pop();
		if(now==n) break;//到达n位置，结束
		for(int i = 0;i < g[now].size();i++) {//遍历所有点
			node tmp = g[now][i];
			if(vis[tmp.index]) continue;//如果当前边被删除，跳过
			if(dis[tmp.dot]!=-1) continue;//如果当前点已遍历，跳过
			dis[tmp.dot] = dis[now] + 1;//更新距离
			if(sav) {//如果要保存的话，记录当前点的上一个点以及边
				from[tmp.dot] = {now, tmp.index};
			}
			q.push(tmp.dot);
		}
	}
}
int main() {
	fast;
	cin>>n>>m;
	for(int i = 1;i <= m;i++) {
		int u,v;
		cin>>u>>v;
		g[u].push_back({v, i});//单向边
	}
	bfs(1);//先计算一次无限制情况下的最短路径
	if(dis[n]==-1) {//如果不可到达，那么表示删除任何边都到达不了
		for(int i = 1;i <= m;i++) cout<<-1<<"\n";
		return 0;
	}
	int pos = n,ans = dis[n];//记录无限制的结果
	set<int> st;//存储边的编号
	while(pos!=1) {//倒着走，记录最短路径中的所有边
		node last = from[pos];//上一个位置
		st.insert(last.index);//添加对应边的索引
		pos = last.dot;//移到上一个位置
	}
	for(int i = 1;i <= m;i++) {//遍历所有边
		if(st.find(i)==st.end()) {//如果这边没有记录过，那么表示对原结果无影响
			cout<<ans<<"\n";
			continue;
		}
		vis[i] = 1;//标记
		bfs(1);	
		vis[i] = 0;//取消标记
		cout<<dis[n]<<"\n";
	}
    return 0;
}
