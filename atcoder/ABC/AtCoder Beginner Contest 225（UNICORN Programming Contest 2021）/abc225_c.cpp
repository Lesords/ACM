// Problem: C - Calendar Validator
// Contest: AtCoder - UNICORN Programming Contest 2021(AtCoder Beginner Contest 225)
// URL: https://atcoder.jp/contests/abc225/tasks/abc225_c
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Author：Lese
// Time：2021-11-09 20:40:31

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
const int MAXN = 1e4+5;
const int MOD = 1e9+7;
const double pi = acos(double(-1));
int a[MAXN][10];
int main() {
	int n, m;
	cin >> n >> m;
	bool ok = 1;
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= m;j++) {
			cin >> a[i][j];
			if(j!=1&&a[i][j]!=a[i][j-1]+1) {
				ok = 0;
			}
			if(i!=1&&a[i][j]!=a[i-1][j]+7) {
				ok = 0;
			}
			// 上一行和下一行连接在一起的情况！！！
			if(a[i][j]%7==0&&j!=m) ok = 0;
		}
	}
	puts(ok?"Yes":"No");
    return 0;
}
