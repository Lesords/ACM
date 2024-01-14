// Problem: Prime Test
// Contest: Virtual Judge - POJ
// URL: https://vjudge.net/problem/POJ-1811
// Memory Limit: 65 MB
// Time Limit: 6000 ms
// 
// Author：Lese
// Time：2021-09-18 11:26:23

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


// Miller-Rabin
long long mul(long long a, long long b, long long p) {
    return (a * b - (long long) (a / (long double) p * b + 1e-3) * p + p) % p;
}
long long poww(long long a, long long n, long long mod) {
    long long res = 1;//mul为快速乘（3.6）
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

    return true;//true为是质数
}

// PollardRho起点
long long gcd(long long a, long long b) {
    return b ? gcd(b, a % b) : a;
}

namespace PollardRho {
    long long g(long long x, long long n, long long c) {
        return (mul(x, x, n) + c) % n;
    }

    long long rho(long long n, long long c) {
        long long x = rand() % n, y = x, d = 1;

        for (long long i = 1, k = 2; d == 1; i++) {
            x = g(x, n, c);
            d = gcd(x > y ? x - y : y - x, n);
            if (x == y) return n;
            if (i == k) k <<= 1, y = x;
        }

        return d;
    }

    void find(long long n, long long c, std::map<long long, int> &res) {
        if (n == 1) return;
        if (isPrime(n)) {
            res[n]++;
            return;
        }

        long long p = n;
        while (p == n) p = rho(p, c++);
        find(p, c, res);
        find(n / p, c, res);
    }

    std::map<long long, int> divide(long long n) {
        static std::map<long long, int> res;
        res.clear();
        find(n, 1, res);
        return res;
    }
}

int main() {
	fast;
    int t;
    cin>>t;
    while(t--) {
    	ll a;
    	cin>>a;
    	if(isPrime(a)) cout<<"Prime\n";
    	else {
    		map<ll, int> ans = PollardRho::divide(a);
    		cout<<(ans.begin()->fi)<<"\n";
    	}
    }
    return 0;
}
