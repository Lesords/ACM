// Problem: P3846 [TJOI2007] 可爱的质数/【模板】BSGS
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3846
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Author：Lese
// Time：2021-09-18 13:08:58

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

// 快 7ms
#define MOD 76543
ll hs[MOD],head[MOD],nextt[MOD],id[MOD],top;
void insert(int x,int y){
	ll k = x%MOD;
	hs[top] = x, id[top] = y, nextt[top] = head[k], head[k] = top++;
}
ll find(ll x){
	ll k = x%MOD;
	for(int i = head[k]; i != -1; i = nextt[i])
		if(hs[i] == x)
		return id[i];
	return -1;
}
ll BSGS(ll a, ll b, ll n) {//a为底数，b为值，n为模数
	memset(head, -1, sizeof(head));
	top = 1;
	if(b == 1)return 0;
	ll m = sqrt(n*1.0), j;
	long long x = 1, p = 1;
	for(int i = 0; i < m; ++i, p = p*a%n)insert(p*b%n,i);
	for(long long i = m; ;i += m){
		if( (j = find(x = x*p%n)) != -1) return i-j;
		if(i > n)break;
	}
	return -1;
}



//偏慢 20ms
// long long pow(long long a, long long n, long long p) {
    // long long res = 1;
    // for (; n; n >>= 1, a = a * a % p) if (n & 1) res = res * a % p;
    // return res;
// }
// 
// long long inv(long long a, long long p) {
    // return pow(a, p - 2, p);
// }
// long long bsgs(long long a, long long b, long long p) {
    // a %= p, b %= p;
    // if (a == 0) return b == 0 ? 1 : -1;
// 
    // std::map<long long, long long> map;
// 
    // long long m = std::ceil(std::sqrt(p)), t = 1;
    // for (int i = 0; i < m; i++) {
        // if (!map.count(t)) map[t] = i;
        // t = t * a % p;
    // }
// 
    // long long k = inv(t, p), w = b;
    // for (int i = 0; i < m; i++) {
        // if (map.count(w)) return i * m + map[w];
        // w = w * k % p;
    // }
// 
    // return -1;
// }

int main() {
	ll p, b, n;
	cin>>p>>b>>n;
	ll ans = BSGS(b, n, p);
	if(ans==-1) cout<<"no solution\n";
	else cout<<ans;
    return 0;
}
