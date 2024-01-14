// Problem: E - Integers on Grid
// Contest: AtCoder - AtCoder Beginner Contest 224
// URL: https://atcoder.jp/contests/abc224/tasks/abc224_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Author：Lese
// Time：2021-11-11 10:33:35

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

//题意：给定h*w的格子，里面有n个值（对应n个位置），其他位置的值为0
//每个位置可移向值比当前位置大的位置（同行或同列）
//求这 n 个位置可以移向的最多次数
//题解：将所有值从大到小排序，然后当前点可以移向的位置为对应 行或列 的最大值
//计算完之后，注意更新对应行和列的结果即可

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
const double pi = acos(double(-1));
int a[MAXN], x[MAXN], y[MAXN];//a为值，(x, y) 为坐标
int row[MAXN], col[MAXN], dp[MAXN];//row为行的最大值，col为列的最大值，dp为最后结果
map<int, vector<int> > g;//由于值较大，所以用map存储
int main() {
	int h, w, n;
	cin >> h >> w >> n;
	for(int i = 1;i <= n;i++) {
		cin >> x[i] >> y[i] >> a[i];
		g[a[i]].push_back(i);//即对应值的出现位置为i
	}
	//倒着遍历map，即为从大到小排序
	for(auto i = g.rbegin();i != g.rend();i++) {
		// 先计算dp值，然后再更新当前点对对应的行和列的贡献！！！
		for(int j = 0;j < i->se.size();j++) {
			int cur = i->se[j];
			//cur可以走的只有两种，对应行和对应列，所以取两者最大值即可
			dp[cur] = max(row[x[cur]], col[y[cur]]);
		}
		for(int j = 0;j < i->se.size();j++) {
			int cur = i->se[j];
			int r = x[cur], c = y[cur];
			//由于cur对于后面的值来说也可以走的，所以需要+1！！！
			row[r] = max(row[r], dp[cur]+1);
			col[c] = max(col[c], dp[cur]+1);
		}
	}
	for(int i = 1;i <= n;i++) cout << dp[i] << "\n";
    return 0;
}