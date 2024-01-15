// Problem: P1082 [NOIP2012 提高组] 同余方程
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1082
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Author：Lese
// Time：2021-09-11 16:27:02

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
const int MAXN = 2e5+5;
const int MOD = 1e9+7;
const double pi = acos(double(-1));
ll exgcd(ll a, ll b, ll &x,ll &y) {
	if(b==0) { x = 1, y = 0; return a;}
	ll d = exgcd(b, a%b, x, y);
	ll z = x; x = y; y = z - y * (a/b);
	return d;
}
int main() {
	ll a, b, x, y;
	cin>>a>>b;
	exgcd(a, b, x, y);
	cout<<(x%b+b)%b;//由于原式中mod的值是b，所以可以%b
    return 0;
}
