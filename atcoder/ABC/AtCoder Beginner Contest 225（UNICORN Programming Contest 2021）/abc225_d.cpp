// Problem: D - Play Train
// Contest: AtCoder - UNICORN Programming Contest 2021(AtCoder Beginner Contest 225)
// URL: https://atcoder.jp/contests/abc225/tasks/abc225_d
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Author：Lese
// Time：2021-11-09 20:53:09

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
int lft[MAXN], rgt[MAXN];
int main() {
	int n, m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++) {
		lft[i] = rgt[i] = i;
	}
	for(int i = 1;i <= m;i++) {
		int op, x, y;
		cin >> op;
		if(op==1) {
			cin >> x >> y;
			lft[y] = x;
			rgt[x] = y;
		}
		else if(op==2) {
			cin >> x >> y;
			lft[y] = y;
			rgt[x] = x;
		}
		else {
			cin >> x;
			deque<int> dq;
			while(lft[x] != x) {
				x = lft[x];
			}
			// 由于是双向的，所以可以先走到最左边，然后再往右边记录答案
			dq.push_back(x);
			while(rgt[x] != x) {
				x = rgt[x];
				dq.push_back(x);
			}
			cout << dq.size();
			while(!dq.empty()) {
				cout << " " << dq.front();
				dq.pop_front();
			}
			cout << "\n";
		}
	}
    return 0;
}
