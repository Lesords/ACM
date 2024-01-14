// Problem: C - Long Sequence
// Contest: AtCoder - AtCoder Beginner Contest 220
// URL: https://atcoder.jp/contests/abc220/tasks/abc220_c
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Author：Lese
// Time：2021-09-26 20:00:17

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
ll a[MAXN];
int main() {
    int n;
    cin>>n;
    ll sum = 0, x;
    for(int i = 1;i <= n;i++) {
    	cin>>a[i];
    	sum += a[i];
    }
    cin>>x;
    ll ans = x/sum;
    ll res = x - sum*ans;
    ans *= n;
    for(int i = 1;i <= n;i++) {
    	if(res<0) break;
    	ans++;
    	res -= a[i];
    }
    cout<<ans<<"\n";
    return 0;
}
