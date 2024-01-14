// Problem: D - Restricted Permutation
// Contest: AtCoder - AtCoder Beginner Contest 223
// URL: https://atcoder.jp/contests/abc223/tasks/abc223_d
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Author：Lese
// Time：2021-10-17 20:35:22

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

//题解：建图之后跑拓扑排序即可

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
const double pi = acos(double(-1));
vector<int> g[MAXN];
int in[MAXN];
int main() {
	int n, m;
	cin >> n >> m;
	for(int i = 1;i <= m;i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		in[v]++;
	}
	priority_queue<int, vector<int>, greater<int> > q;
	for(int i = 1;i <= n;i++) {
		if(in[i]==0) {
			q.push(i);
		}
	}
	vector<int> ans;
	while(!q.empty()) {
		int dot = q.top();
		q.pop();
		ans.push_back(dot);
		for(int i = 0;i < g[dot].size();i++) {
			int now = g[dot][i];
			if(--in[now]==0) q.push(now);
		}
	}
	if(ans.size()!=n) {
		cout << "-1\n";
		return 0;
	}
	for(auto v:ans) cout << v << " ";
    return 0;
}
