// Problem: 绿豆蛙的归宿
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/219/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// 
// Author：Lese
// Time：2021-10-15 19:44:19

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

//题解：反向建图跑拓扑排序
//边跑边计算对应期望即可
//注意转移对应的期望值

const int MAXN = 1e5+5;
const int MOD = 1e9+7;
const double pi = acos(double(-1));
struct node{
	int v, val;
};
double dp[MAXN];
int num[MAXN], in[MAXN];
vector<node> g[MAXN];
int main() {
	int n, m;
	cin >> n >> m;
	for(int i = 1;i <= m;i++) {
		int u, v, w;
		cin >> u >> v >> w;
		g[v].push_back({u, w});//反向建图
		num[u]++;
		in[u]++;
	}
	queue<int> q;
	q.push(n);
	while(!q.empty()) {
		int dot = q.front();
		q.pop();
		for(int i = 0;i < g[dot].size();i++) {
			int x = g[dot][i].v;
			int val = g[dot][i].val;
			//x可以走向dot位置
			//x可以走的道路数量为num[x]
			//当前指向期望值包括 对应点的期望值+边权值
			dp[x] = (dp[x]+ double(dp[dot]+val)/num[x]);
			if(--in[x]==0) q.push(x);
		}
	}
	printf("%.2f", dp[1]);
    return 0;
}
