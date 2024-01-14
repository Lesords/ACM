// Problem: D - Teleportation
// Contest: AtCoder - AtCoder Beginner Contest 226
// URL: https://atcoder.jp/contests/abc226/tasks/abc226_d
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Author：Lese
// Time：2021-11-07 20:27:41

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
const int MAXN = 505;
const int MOD = 1e9+7;
const double pi = acos(double(-1));
int x[MAXN], y[MAXN];
int gcd(int a, int b) {
	return a%b==0?b:gcd(b, a%b);
}
pii solve(int a, int b) {
	if(a==0) {
		return {0, b>0?1:-1};
	}
	if(b==0) {
		return {a>0?1:-1, 0};
	}
	int mark = a > 0 ?1:-1;
	int mark2 = b > 0 ?1:-1;
	a = abs(a), b = abs(b);
	return {a/gcd(a, b)*mark, b/gcd(a, b)*mark2};
}
int main() {
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++) {
		cin >> x[i] >> y[i];
	}
	set<pii> st;
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) {
			if(i==j) continue;
			int disX = x[j]-x[i];
			int disY = y[j]-y[i];
			pii val = solve(disX, disY);
			st.insert(val);
		}
	}
	cout << st.size() << "\n";
    return 0;
}
