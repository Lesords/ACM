// Problem: P3811 【模板】乘法逆元
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3811
// Memory Limit: 125 MB
// Time Limit: 500 ms
// 
// Author：Lese
// Time：2021-09-12 16:11:11

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
const int MAXN = 3e6+6;
const int MOD = 1e9+7;
const double pi = acos(double(-1));

ll inv[MAXN];
int main() {
	int n,p;
	cin>>n>>p;
	inv[1] = 1;
	cout<<1<<"\n";
	for(int i = 2;i <= n;i++) {
		inv[i] = (p-p/i)*inv[p%i]%p;
		cout<<inv[i]<<"\n";
	}
    return 0;
}
