// Problem: C - Martial artist
// Contest: AtCoder - AtCoder Beginner Contest 226
// URL: https://atcoder.jp/contests/abc226/tasks/abc226_c
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Author：Lese
// Time：2021-11-07 20:02:54

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

//题解：倒着建图，然后从后往前开始遍历，记录所有需要学习的动作，并且累计结果

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
const double pi = acos(double(-1));
vector<int> g[MAXN];
ll tim[MAXN];
int vis[MAXN];
int main() {
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++) {
		cin >> tim[i];
		int num, tmp;
		cin >> num;
		for(int j = 1;j <= num;j++) {
			cin >> tmp;
			g[i].push_back(tmp);//存图
		}
	}
	ll ans = 0;
	vis[n] = 1;
	for(int i = n;i >= 1;i--) {//从后往前开始记录所有需要学习的动作
		if(vis[i]) {
			ans += tim[i];//当前动作需要学习，所以累加结果
			for(int j = 0;j < g[i].size();j++) {//遍历所有前置动作
				vis[g[i][j]] = 1;
			}
		}
	}
	cout << ans << "\n";
    return 0;
}
/*
5
1 0
2 1 1
3 1 2
4 1 3
5 1 4

15
*/