// Problem: C - Triangle?
// Contest: AtCoder - AtCoder Beginner Contest 224
// URL: https://atcoder.jp/contests/abc224/tasks/abc224_c
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Author：Lese
// Time：2021-10-23 20:06:33

#include<iostream>//ac
#include<assert.h>
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
#define uint int
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define pii pair<int,int>
#define fi first
#define se second
#define eps 1e-6
#define lson rt<<1
#define rson rt<<1|1
#define Two(x) (x) * (x)
using namespace std;

//题解：遍历所有三个点，判断是否可以组成一个三角形即可
//也就是说，排除三个点在同一直线的情况即可

const int MAXN = 305;
const int MOD = 1e9+7;
const double pi = acos(double(-1));
struct node{
	ll x,y;
}a[MAXN];
int main() {
	fast;
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++) {
		cin >> a[i].x >> a[i].y;
	}
	int ans = 0;
	for(int i = 1;i <= n;i++) {
		for(int j = i+1;j <= n;j++) {
			for(int k = j+1;k <= n;k++) {
				// 按顺序计算，因为根据最大值 - 最小值的话，对应的位置会发生变化
				ll delx = a[i].x - a[j].x;
				ll dely = a[i].y - a[j].y;
				ll del2x = a[k].x - a[j].x;
				ll del2y = a[k].y - a[j].y;
				if(delx * del2y == del2x * dely) continue;
				ans++;
			}
		}
	}
	cout << ans;
    return 0;
}
