// Problem: D - FG operation
// Contest: AtCoder - AtCoder Beginner Contest 220
// URL: https://atcoder.jp/contests/abc220/tasks/abc220_d
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Author：Lese
// Time：2021-09-26 20:00:20

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
const int MOD = 998244353;
const double pi = acos(double(-1));
ll dp[MAXN][10];//当前位置i，结果为j的数量
int a[MAXN];
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) {
    	cin>>a[i];
    	a[i] %= 10;
    }
    dp[1][a[1]] = 1;
    for(int i = 2;i <= n;i++) {
    	for(int j = 0;j < 10;j++) {
    		if(dp[i-1][j]==0) continue;
    		dp[i][j*a[i]%10] = (dp[i][j*a[i]%10] + dp[i-1][j])%MOD;
    		dp[i][(j+a[i])%10] = (dp[i][(j+a[i])%10] + dp[i-1][j])%MOD;
    	}
    }
    for(int i = 0;i < 10;i++) {
    	cout<<dp[n][i]%MOD<<"\n";
    }
    return 0;
}
