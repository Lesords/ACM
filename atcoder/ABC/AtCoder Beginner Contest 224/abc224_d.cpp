// Problem: D - 8 Puzzle on Graph
// Contest: AtCoder - AtCoder Beginner Contest 224
// URL: https://atcoder.jp/contests/abc224/tasks/abc224_d
// Memory Limit: 1024 MB
// Time Limit: 4000 ms
// 
// Author：Lese
// Time：2021-10-23 21:22:51

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
const int MAXN = 2e5+5;
const int MOD = 1e9+7;
const double pi = acos(double(-1));
vector<int> g[10];
int pos[10];
int main() {
	fast;
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	string s = "0999999999";//由于从1开始，所以0位置多出一个0（只占位置）
	for(int i = 1;i <= 8;i++) {
		int tmp;
		cin >> tmp;//点tmp上有i
		s[tmp] = i+'0';//因为转移是根据点来决定的，所以利用 点 来存储
	}
	map<string, int> num;//记录到对应状态的结果数
	queue<string> q;
	q.push(s);
	num[s] = 0;
	while(!q.empty()) {
		int now = 0;
		s = q.front();q.pop();
		for(int i = 1;i <= 9;i++) if(s[i]=='9') now = i;
		for(auto v:g[now]) {
			string t = s;
			swap(t[now], t[v]);
			if(num.count(t)) continue;
			num[t] = num[s] + 1;
			q.push(t);
		}
	}
	// 目的结果为 123456789，由于有占位0，所以为 0123456789
	if(num.count("0123456789")==0) cout << "-1";
	else cout << num["0123456789"]; 
    return 0;
}
