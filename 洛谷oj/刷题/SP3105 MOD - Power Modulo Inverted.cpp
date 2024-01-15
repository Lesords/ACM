// Problem: SP3105 MOD - Power Modulo Inverted
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/SP3105
// Memory Limit: 1.46 MB
// Time Limit: 4000 ms
// 
// Author：Lese
// Time：2021-09-18 11:57:37

#include<iostream>//?
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
ll BSGS(ll a, ll b, ll n){
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


int gcd(int a, int b) { return a ? gcd(b % a, a) : b; }
int powmod(int a, int b, int p) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % p;
    a = a * a % p, b >>= 1;
  }
  return res;
}
// Finds the primitive root modulo p
int generator(int p) {
  vector<int> fact;
  int phi = p - 1, n = phi;
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      fact.push_back(i);
      while (n % i == 0) n /= i;
    }
  }
  if (n > 1) fact.push_back(n);
  for (int res = 2; res <= p; ++res) {
    bool ok = true;
    for (int factor : fact) {
      if (powmod(res, phi / factor, p) == 1) {
        ok = false;
        break;
      }
    }
    if (ok) return res;
  }
  return -1;
}

int main() {
	fast;
	ll x, z, k;
	while(cin>>x>>z>>k&&x+z+k) {
		ll val = generator(x, k, z);
		if(val==-1) cout<<"No Solution\n";
		else cout<<val<<"\n";
	}
    return 0;
}
