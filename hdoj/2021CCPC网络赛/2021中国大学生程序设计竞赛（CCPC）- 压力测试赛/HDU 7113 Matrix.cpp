// Problem: Matrix
// Contest: HDOJ
// URL: http://acm.hdu.edu.cn/showproblem.php?pid=7113
// Memory Limit: 524 MB
// Time Limit: 2000 ms
// 
// Author：Lese
// Time：2021-10-25 23:57:26

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
const int MAXN = 5e3+5;
const int MOD = 998244353;
const double pi = acos(double(-1));

//题解：
//对于每个i的贡献为： n * C(n*n-i, n-1) * n! * (n*2-n)!
//1. i在当前行有n个位置可以摆放
//2. 要想i在当前行有贡献（即最小值），则另外n-1个数都需要比i大
//则共有 n*n-i个数可选，选 n-1 个，即 C(n*n-i, n-1)
//3. 由于 包括当前i的行 在哪个位置，结果都不受影响
//所以可以累计 当前行可以位于的位置 次数（所有行的排列），即 n!
//4. 由于其他行（不包括当前行）的数与当前i无关，所以其他行的排列可任意，为 (n*n-n)!

ll f[MAXN*MAXN];//存储阶乘
void init(int p) {//记得先初始化阶乘！！！
	f[0] = 1;
	for(int i = 1;i < p;i++) {
		f[i] = (f[i-1] * i)%MOD;
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
ll C(ll n, ll m, ll p) {//C(n, m)
	if(m>n) return 0;
	return ((f[n]*poww(f[m], p-2, p))%p * poww(f[n-m], p-2, p))%p;
}
ll lucas(ll n, ll m, ll p) {
	if(m==0) return 1;
	return (lucas(n/p, m/p, p) * C(n%p, m%p, p)) %p;
}
// 用lucas计算组合数

int main() {
	fast;
	init(MAXN*MAXN-1);//注意有n*n的情况！！！
    int t;
    cin>>t;
    while(t--) { 
    	int n;
    	cin >> n;
    	ll ans = 0;
    	for(int i = 1;i <= n;i++) {
    		ans = (ans + n*lucas(n*n-i, n-1, MOD)%MOD * f[n]%MOD * f[n*n-n]%MOD)%MOD;
    		// 多取模，防止爆了
    	}
    	cout << ans%MOD << "\n";
    }
    return 0;
}
