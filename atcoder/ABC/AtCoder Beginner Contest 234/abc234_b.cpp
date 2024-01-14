// Problem: B - Longest Segment
// Contest: AtCoder - AtCoder Beginner Contest 234
// URL: https://atcoder.jp/contests/abc234/tasks/abc234_b
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Author：Lese
// Time：2022-01-08 20:03:05

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
#define two(x) (x) * (x)
using namespace std;
const int MAXN = 106;
const int MOD = 1e9+7;
const double pi = acos(double(-1));
int x[MAXN], y[MAXN];
double solve(int a, int b) {
	return sqrt(two(x[a]-x[b]) + two(y[a]-y[b]));
}
int main() {
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++) {
		cin >> x[i] >> y[i];
	}
	double ans = 0;
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) {
			ans = max(ans, solve(i, j));
		}
	}
	printf("%.10f", ans);
    return 0;
}
