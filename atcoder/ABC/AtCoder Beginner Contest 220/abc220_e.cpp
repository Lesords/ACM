// Problem: E - Distance on Large Perfect Binary Tree
// Contest: AtCoder - AtCoder Beginner Contest 220
// URL: https://atcoder.jp/contests/abc220/tasks/abc220_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Author：Lese
// Time：2021-09-26 20:00:24

#include<iostream>//wa
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
const int MOD = 998244353;
const double pi = acos(double(-1));

ll poww(ll a, ll b, ll p) {//a的b次方
	ll ans = 1;//ans为结果
	while(b) {
		if(b&1) ans = (ans*a)%p;
		a = (a*a)%p;//二进制每次乘都要翻倍 
		b >>= 1;
	}
	return ans%p;   
}

int main() {
	int n, d;
	cin>>n>>d;
	ll ans = 0;
	d++;
	for(int i = n;i > d/2;i--) {
		if(i>=d) {
			ll tmp = poww(2, n-d+1, MOD)-1;
			ans = (ans + poww(2, i-1, MOD)*tmp) %MOD;
		}
		else {
			ll tmp = 0;
			ll res = d-i+1;
			ll a = poww(2, i-1, MOD)/2;
			ll b = poww(2, res-1, MOD)/2;
			tmp = (a*b)%MOD;
			if(i!=res) {
				tmp = (tmp*2)%MOD;
			}
			tmp = (tmp* (poww(2, n-i+1, MOD)-1))%MOD;
			ans = (ans+tmp+MOD)%MOD;
		}
	}
	cout<<(ans*2+MOD)%MOD<<"\n";
    return 0;
}
