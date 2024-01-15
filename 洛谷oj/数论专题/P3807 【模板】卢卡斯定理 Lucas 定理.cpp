// Problem: P3807 【模板】卢卡斯定理/Lucas 定理
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3807
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Author：Lese
// Time：2021-09-10 08:55:16

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

//题解：Lucas模板题
//需要注意组合数求解的时候用的是费马小公式求的逆元
//而且还需要预处理下阶乘

ll f[MAXN];
void init(int p) {//预处理到p的阶乘
	f[0] = 1;
	for(int i = 1;i < p;i++) {
		f[i] = (f[i-1] * i)%p;
	}
}
ll poww(ll a,ll b, ll p) {//a^b
	ll ans = 1;
	while(b) {
		if(b&1) ans = (ans*a)%p;
		a = (a*a)%p;
		b >>= 1;
	}
	return ans%p;
}
ll C(ll n, ll m, ll p) {
	if(m>n) return 0;
	return ((f[n]*poww(f[m], p-2, p))%p * poww(f[n-m], p-2, p))%p;
}
ll lucas(ll n, ll m, ll p) {
	if(m==0) return 1;
	return (lucas(n/p, m/p, p) * C(n%p, m%p, p)) %p;
}
int main() {
    int t;
    cin>>t;
    while(t--) {
    	ll n,m,q;
    	cin>>n>>m>>q;
		init(q);
    	cout<<lucas(n+m, n,q)<<"\n";
    }
    return 0;
}
