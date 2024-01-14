// Problem: D - Prefix K-th Max
// Contest: AtCoder - AtCoder Beginner Contest 234
// URL: https://atcoder.jp/contests/abc234/tasks/abc234_d
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Author：Lese
// Time：2022-01-08 20:16:16

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
const int MAXN = 5e5+5;
const int MOD = 1e9+7;
const double pi = acos(double(-1));
int a[MAXN];
int main() {
	int n, k;
	priority_queue<int, vector<int>, greater<int> > q;
	cin >> n >> k;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
		q.push(a[i]);
		if(i >= k) {
			while(q.size() > k) q.pop();
			cout << q.top() << "\n";
		}
	}
    return 0;
}
