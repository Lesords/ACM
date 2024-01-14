// Problem: Jumping Monkey
// Contest: HDOJ
// URL: http://acm.hdu.edu.cn/showproblem.php?pid=7136
// Memory Limit: 262 MB
// Time Limit: 8000 ms
// 
// Author：Lese
// Time：2021-10-11 16:46:39

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

//题意：在一个树上，如果目的点的权值是 当前位置到目的点 的路径中的最大权值
//那么则可以从当前位置跳到目的点，求每个点可以跳到的最多数量（包括本身）
//题解：首先需要明白树中权值最大的点肯定为最后一个可以跳的点
//那么对应权值最大的点来说，实际上把当前点断开了，剩余的位置都不可互相跳
//在剩余的位置里可以再找权值最大的点，重复这个过程，即可找出对应的路径

//但是这个过程显然不好计算，所以可以反向来理解
//将权值从小到大排序，遍历到每个点的时候，遍历所有与其相连点
//如果指向点的权值大于当前的点，则跳过
//否则 寻找指向点当前可以走向的最远位置，然后使当前点与其相连
//接着更新指定点可以走向的最远位置为当前点
//最后建成的即为一颗树，对应的根即为可以走向的最远位置
//每个点的路径，即为从当前点走向根节点（对应的值即为深度，根的深度为1）
//可以用并查集来维护 走向的最远位置

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
const double pi = acos(double(-1));
struct node {
	int val, pos;
	friend bool operator < (node a, node b) {
		return a.val < b.val;//按照边权值从小到大排序
	}
}data[MAXN];
int n, a[MAXN], dis[MAXN], dep[MAXN];//dis记录走向的最远位置，dep为深度（即结果）
vector<int> g[MAXN], h[MAXN];//g为原边，h为建图后的边
int getf(int pos) {
	return dis[pos] == pos?pos:dis[pos] = getf(dis[pos]);
}
void dfs(int now, int fa) {//计算建完后的树的各个节点深度
	dep[now] = dep[fa]+1;
	for(auto v:h[now]) {
		if(v==fa) continue;
		dfs(v, now);
	}
}
int main() {
	fast;
    int t;
    cin >> t;
    while(t--) {
    	cin >> n;
    	for(int i = 1;i <= n;i++) g[i].clear(), h[i].clear();//清空所有边
    	for(int i = 1;i < n;i++) {
    		int u, v;
    		cin >> u >> v;
    		g[u].push_back(v);//无向边
    		g[v].push_back(u);
    	}
    	for(int i = 1;i <= n;i++) {
    		cin >> a[i];
    		data[i] = {a[i], i};//记录边权值和下标
    		dis[i] = i;//更新 最远位置 为本身
    	}
    	sort(data+1, data+n+1);
    	for(int i = 2;i <= n;i++) {//从第二个点开始，因为第一个肯定为叶子节点
    		int id = data[i].pos;//id为当前位置
    		for(auto v:g[id]) {
    			if(a[v] > a[id]) continue;//跳过权值大于当前位置的指向点
    			v = getf(v);//获取v点可以走向的最远位置
    			dis[v] = id;//更新对应位置为当前点（对于以v为根的子树来说，id的权值是最大的）
    			h[id].push_back(v);//建边
    		}
    	}
    	dep[0] = 0;
    	dfs(data[n].pos, 0);//计算对应的深度
    	for(int i = 1;i <= n;i++) {
    		cout << dep[i] << "\n";
    	}
    }
    return 0;
}
