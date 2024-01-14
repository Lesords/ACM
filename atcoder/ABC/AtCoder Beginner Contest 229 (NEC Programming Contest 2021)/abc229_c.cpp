// Problem: C - Cheese
// Contest: AtCoder - NEC Programming Contest 2021(AtCoder Beginner Contest 229)
// URL: https://atcoder.jp/contests/abc229/tasks/abc229_c
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Author：Lese
// Time：2021-11-27 20:16:30

#include<iostream>
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
const int MAXN = 3e5+5;
const int MOD = 1e9+7;
const double pi = acos(double(-1));
struct node{
	ll val, num;
	friend bool operator < (node a, node b) {
		return a.val > b.val;
	}
}a[MAXN];
int main() {
	int n;
	ll w, sum = 0, last = 0;
	cin >> n >> w;
	for(int i = 1;i <= n;i++) {
		cin >> a[i].val >> a[i].num;
	}
	sort(a+1, a+1+n);
	for(int i = 1;i <= n;i++) {
		if(sum+a[i].val > w) continue;
		ll num = (w-sum)/a[i].val;
		sum += a[i].val*min(a[i].num, num);
	}
	cout << sum;
    return 0;
}
