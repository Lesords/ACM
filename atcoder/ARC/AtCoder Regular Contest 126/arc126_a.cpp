// Problem: A - Make 10
// Contest: AtCoder - AtCoder Regular Contest 126
// URL: https://atcoder.jp/contests/arc126/tasks/arc126_a
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Author：Lese
// Time：2021-09-19 21:02:36

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
int main() {
    int t;
    cin>>t;
    while(t--) {
    	ll a, b, c;
    	cin>>a>>b>>c;
    	ll ans = 0;
    	ll tmp = 0;
    	
    	tmp = min(c, b/2);
    	ans = tmp;
    	c -= tmp;
    	b -= tmp*2;
    	
    	tmp = min(a/2, b/2);
    	ans += tmp;
    	a -= tmp*2;
    	b -= tmp*2;
    	
    	tmp = min(a, c/2);
    	ans += tmp;
    	a -= tmp;
    	c -= tmp*2;
    	
    	tmp = min(a/3, c);
    	ans += tmp;
    	a -= tmp*3;
    	c -= tmp;
    	
    	tmp = a/5;
    	ans += tmp;
    	cout<<ans<<"\n";
    }
    return 0;
}
