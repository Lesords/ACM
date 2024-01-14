// Problem: G - Game on Tree 2
// Contest: AtCoder - AtCoder Beginner Contest 218
// URL: https://atcoder.jp/contests/abc218/tasks/abc218_g
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Author：Lese
// Time：2021-09-13 22:08:26

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
const int MAXN = 1e5+5;
const int MOD = 1e9+7;
const double pi = acos(double(-1));
vector<int> g[MAXN];
multiset<int> one,two;//对顶堆思想记录中间值
int a[MAXN],dp[MAXN];
void adjust() {//调整两个堆的状态
	//因为此时放入one中的值不一定会小于two中的值
	//所以需要将较大的值放入two中，然后再判断是否需要从two中取值到one中
	//也就是说one中的较大值移到two中，two中的较小值移到one中
	if(one.size()) {
		auto last = one.end();
		last--;
		two.insert(*last);
		one.erase(last);
	}
	while(one.size()<two.size()) {
		one.insert(*two.begin());
		two.erase(two.begin());
	}
}
void Erase(int val) {//删除val值
	auto last = one.end();
	last--;
	if(val<=*last) one.erase(one.lower_bound(val));
	else two.erase(two.lower_bound(val));
}
int val() {//获取当前的中间值
	auto last = one.end();
	last--;
	if(one.size()==two.size()+1) return *last;
	return (*last + *two.begin())/2;
}
//pos为当前位置，fa为上一个位置，dep为深度（也可为操作次数）
void dfs(int pos,int fa,int dep) {//计算结果
	one.insert(a[pos]);
	adjust();
	int minn = INF, maxx = 0;
	for(int i = 0;i < g[pos].size();i++) {
		int now = g[pos][i];
		if(now==fa) continue;
		dfs(now, pos, dep+1);
		minn = min(minn, dp[now]);
		maxx = max(maxx, dp[now]);
	}
	//计算当前节点的值
	if(maxx==0) dp[pos] = val();
	else if(dep&1) dp[pos] = maxx;
	else dp[pos] = minn;
	Erase(a[pos]);
	adjust();
}
int main() {
	int n;
	cin>>n;
	for(int i = 1;i <= n;i++) cin>>a[i];
	for(int i = 1;i < n;i++) {
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, -1, 1);
	cout<<dp[1];
    return 0;
}
