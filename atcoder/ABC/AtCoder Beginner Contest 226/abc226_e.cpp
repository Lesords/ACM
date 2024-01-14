// Problem: E - Just one
// Contest: AtCoder - AtCoder Beginner Contest 226
// URL: https://atcoder.jp/contests/abc226/tasks/abc226_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Author：Lese
// Time：2021-11-08 10:59:38

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

//题解：要想满足条件，首先需要确定有环，环内的方向是顺时针或者逆时针，环外的点指向环的方向
//由于不满足为联通图，所以可以分别计算每个联通分量
//只要有一个联通分量不满足条件，结果就为0
//否则结果为 2^k，其中k为联通分量个数

//判定对一个联通分量是否满足条件，可以用dfs记录所有出现过的边和点
//如果对应点记录的数量为边的两倍，那么满足条件；否则不满足条件

const int MAXN = 2e5+5;
const int MOD = 998244353;
const double pi = acos(double(-1));
vector<int> g[MAXN];		//存图
bool vis[MAXN];				//判断对应点是否遍历过（联通分量
int dot, edge;				//dot为对应的点数遍历数量，edge为对于的边遍历的数量
void dfs(int pos) {			//当前点为pos
	vis[pos] = 1;			//标记当前点
	edge++;					//能遍历，说明当前位置有一条边
	dot += g[pos].size();	//累积对应指向点的数量
	//（由于是无向边，两个方向都计算，所以点的数量应该为边的两倍）
	for(int i = 0;i < g[pos].size();i++) {//遍历所有指向点
		int now = g[pos][i];
		if(vis[now]) continue;//若已标记，跳过
		dfs(now);
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	for(int i = 1;i <= m;i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);			//存图
		g[v].push_back(u);
	}
	int ans = 1;
	for(int i = 1;i <= n;i++) {
		if(vis[i]) continue;		//如果已经遍历，跳过
		dot = edge = 0;				//初始化为0
		dfs(i);
		// 如果满足条件，更新结果，注意取模
		if(dot==edge*2) ans = (ans*2) % MOD;
		else {
			// 不满足条件，结果为0，直接结束
			ans = 0;break;
		}
	}
	cout << ans << "\n";
    return 0;
}
