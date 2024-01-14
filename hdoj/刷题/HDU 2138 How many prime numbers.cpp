// Problem: How many prime numbers
// Contest: HDOJ
// URL: https://acm.hdu.edu.cn/showproblem.php?pid=2138
// Memory Limit: 32 MB
// Time Limit: 3000 ms
// 
// Author：Lese
// Time：2021-09-18 11:14:08

#include<iostream>
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

long long mul(long long a, long long b, long long p) {
    return (a * b - (long long) (a / (long double) p * b + 1e-3) * p + p) % p;
}
long long poww(long long a, long long n, long long mod) {
    long long res = 1;
    for (; n; n >>= 1, a = mul(a, a, mod)) if (n & 1) res = mul(res, a, mod);
    return res;
}
bool isPrime(long long n) {
    const static int primes[12] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

    long long s = 0, d = n - 1;
    while (d % 2 == 0) d /= 2, s++;
    if (s == 0) return n == 2;

    for (int i = 0; i < 12 && primes[i] < n; i++) {
        long long a = primes[i];
        if (poww(a, d, n) != 1) {
            bool flag = true;
            for (int r = 0; r < s; r++)
                if (flag && poww(a, d * (1 << r), n) == n - 1) flag = false;
            if (flag) return false;
        }
    }

    return true;//true为质数
}

int main() {
	fast;
	int n;
	while(cin>>n) {
		int ans = 0,tmp;
		for(int i = 1;i <= n;i++) {
			cin>>tmp;
			ans += isPrime(tmp);
		}
		cout<<ans<<"\n";
	}
    return 0;
}
