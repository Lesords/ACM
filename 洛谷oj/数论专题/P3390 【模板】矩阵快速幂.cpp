// Problem: P3390 【模板】矩阵快速幂
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3390
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Author：Lese
// Time：2021-09-16 22:56:41

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
const double pi = acos(double(-1));

const int MAXN = 105;//范围只有100（RE原因）！！！
const int MOD = 1e9+7;
struct matrix{
    int r, c;
    ll s[MAXN][MAXN];
    matrix(int r = 0,int c = 0):r(r),c(c) {
        memset(s, 0, sizeof s);
    }
};
matrix operator* (const matrix& a, const matrix& b) {
    matrix c = matrix(a.r, b.c);
    for (int i = 0; i < c.r;i++) {
        for (int j = 0; j < c.c;j++)
            for (int k = 0; k < a.c;k++)
                // c.s[i][j] += a.s[i][k] * b.s[k][j];
                c.s[i][j] = (c.s[i][j] + a.s[i][k]*b.s[k][j]%MOD)%MOD;//取模
    }
    return c;
}
matrix power(matrix a,ll b) {
    matrix res = a;
    b--;
    while(b) {
    	if(b&1) res = res * a;
    	a = a*a;
    	b >>= 1;
    }
    return res;
}
int main() {
	ll n, k;
	cin>>n>>k;
	matrix a(n, n);//初始化为n行n列
	for(int i = 0;i < n;i++) {
		for(int j = 0;j < n;j++) cin>>a.s[i][j];
	}
	matrix ans = power(a, k);//计算对应矩阵快速幂
	for(int i = 0;i < n;i++) {
		for(int j = 0;j < n;j++) {
			if(j) cout<<" ";
			cout<<(ans.s[i][j]+MOD)%MOD;//记得取模
		}
		cout<<"\n";
	}
    return 0;
}
