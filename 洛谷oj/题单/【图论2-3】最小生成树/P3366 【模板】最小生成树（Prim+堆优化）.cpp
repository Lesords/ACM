// Problem: P3366 【模板】最小生成树
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3366
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// 
// Author：Lese
// Time：2021-09-18 16:08:13

#include<iostream>//ac	注意i和j！！！
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
const int MOD = 1e9+7;
const double pi = acos(double(-1));


const int MAXN = 5e3+5;
struct node {
	int dot, val;
	friend bool operator < (node a, node b) {
		return a.val > b.val;						//优先权值小的
	}
};
int n, m;
bool v[MAXN];										//v记录当前点是否被选过
vector<node> g[MAXN];
int prim(int u) {									//u为起点
	priority_queue<node> q;
    memset(v, 0, sizeof v);							//初始化所有点未访问
    v[u] = 1;										//标记起点
    int ans = 0;
    for(int i = 0;i < g[u].size();i++) {			//起点可以到达的所有位置
    	q.push(g[u][i]);
    }
    for(int i = 1;i < n;i++) {
    	while(!q.empty()&&v[q.top().dot]) q.pop();	//先清空所有已访问的点
    	if(q.empty()) return -1;					//若为空，表示原图不连通
    	node now = q.top();q.pop();					//取队首的点
    	v[now.dot] = 1;
    	ans += now.val;
    	for(int j = 0;j < g[now.dot].size();j++) {	//遍历该点的所有指向点
    		node tmp = g[now.dot][j];
    		if(v[tmp.dot]) continue;				//跳过已访问的点
    		q.push(tmp);
    	}
    }
    return ans;
}
int main() {
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        g[x].push_back({y, z});							//存边
        g[y].push_back({x, z});
    }
    int ans = prim(1);
    if(ans==-1) cout<<"orz";							//不连通
    else cout<<ans;
    return 0;
}