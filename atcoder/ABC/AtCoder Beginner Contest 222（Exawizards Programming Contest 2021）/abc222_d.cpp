// Problem: D - Between Two Arrays
// Contest: AtCoder - Exawizards Programming Contest 2021（AtCoder Beginner Contest 222）
// URL: https://atcoder.jp/contests/abc222/tasks/abc222_d
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Author：Lese
// Time：2021-10-09 20:00:48

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
const int MAXN = 3e3+5;
const int MOD = 998244353;
const double pi = acos(double(-1));
int a[MAXN], b[MAXN];
ll dp[MAXN][MAXN], pre[MAXN];//dp[i][j]表示i位置选j值的数量，pre为上一个dp状态的前缀和
int main() {
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
		a[i]++;//前缀和从1开始，但是数据有0的情况，所以需要++
	}
	for(int i = 1;i <= n;i++) {
		cin >> b[i];
		b[i]++;
	}
	for(int i = a[1];i <= b[1];i++) dp[1][i] = 1;//边界位置，第一个位置都可以选，则值为1
	for(int i = 2;i <= n;i++) {//遍历后面的位置
		pre[0] = 0;
		for(int j = 1;j < MAXN;j++) pre[j] = (pre[j-1] + dp[i-1][j])%MOD;
		for(int j = a[i];j <= b[i];j++) {//遍历所有满足条件的值
			dp[i][j] = (dp[i][j] + (pre[j]))%MOD;
		}
	}
	ll ans = 0;//累加n位置可以选的所有值的结果即为答案
	for(int i = a[n];i <= b[n];i++) ans = (ans + dp[n][i])%MOD;
	cout << (ans+MOD)%MOD;
    return 0;
}
