// Problem: A. Great Graphs
// Contest: Codeforces - Codeforces Round #728 (Div. 1)
// URL: https://codeforces.ml/problemset/problem/1540/A
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Author：Lese
// Time：2021-11-12 14:56:10

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

//题意：给定从第一个牧场到其他牧场的距离，给这些牧场建边，求最小边权和
//注意：每两个牧场可以建两个单向边（正向和逆向）

//题解；由于题目要使边权和尽量小，那么也就是说我们需要使负边权尽量多，正边权尽量小
//为了使正边权尽量小，可以将所有的边权 从小到大 排序，使其称为一条链，此时正边权最小
//那么对于负边权来说：如果当前位置为i，那么可以连接的负边权有 (i-1) * (n-i)
//也就是说使 当前点往后一点 i 到 末点n 为起点; 前 i-1 个点为末点，以此来建负边
//然后再扣除一个正边，即为 (i-1) * (n-i) - 1

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
const double pi = acos(double(-1));
ll a[MAXN];
int main() {
    int t;
    cin>>t;
    while(t--) {
    	int n;
    	cin >> n;
    	for(int i = 1;i <= n;i++) {
    		cin >> a[i];
    	}	
    	sort(a+1, a+n+1);//边权从小到大排序
    	ll ans = 0;
    	for(int i = 2;i <= n;i++) {
    		//注意*1ll！！！
    		ans += ((i-1)*1ll*(n-i+1)-1)*(a[i-1]-a[i]);//a[i-1]-a[i]即为负边权
    	}
    	cout << ans << "\n";
    }
    return 0;
}
