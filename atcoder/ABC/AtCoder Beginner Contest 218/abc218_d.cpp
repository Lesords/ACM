// Problem: D - Rectangles
// Contest: AtCoder - AtCoder Beginner Contest 218
// URL: https://atcoder.jp/contests/abc218/tasks/abc218_d
// Memory Limit: 1024 MB
// Time Limit: 4000 ms
// 
// Author：Lese
// Time：2021-09-11 20:11:25

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
const int MAXN = 2e3+5;
const int MOD = 1e9+7;
const double pi = acos(double(-1));
struct node{
	int x,y;
	friend bool operator < (node a,node b) {
		if(a.x==b.x) return a.y < b.y;
		return a.x < b.x;
	}
}a[MAXN];
int x[MAXN], y[MAXN];
set<pii> st;
int main() {
	int n;
	cin>>n;
	for(int i = 1;i <= n;i++) {
		cin>>x[i]>>y[i];
		a[i] = {x[i], y[i]};
		st.insert({x[i], y[i]});
	}
	sort(a+1, a+n+1);
	int ans = 0;
	for(int i = 1;i <= n;i++) {
		for(int j = i+1;j <= n;j++) {
			if(a[i].x==a[j].x) continue;
			if(a[i].y==a[j].y) continue;
			if(a[i].y>a[j].y) continue;
			pii dot1 = {a[i].x, a[j].y};
			pii dot2 = {a[j].x, a[i].y};
			if(st.find(dot1)!=st.end()&&st.find(dot2)!=st.end()) {
				ans++;
			}
		}
	}
	cout<<ans<<"\n";
    return 0;
}
