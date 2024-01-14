// Problem: D - Project Planning
// Contest: AtCoder - KEYENCE Programming Contest 2021 (AtCoder Beginner Contest 227)
// URL: https://atcoder.jp/contests/abc227/tasks/abc227_d
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Author：Lese
// Time：2021-11-13 20:50:08

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

//题解：二分答案
//首先需要知道，每个位置的最大贡献肯定为 min(a[i], p) p为需要的项目数量
//那么所有位置的贡献，即可判断是否满足总条件 p*k
//那么上诉方法即可为判断方法
//由于值的范围为1e^12，并且有2^5个，那么最大值可以直接设置为 1e18，最小值为0

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
const double pi = acos(double(-1));
ll a[MAXN];
int main() {
	int n, k;
	cin >> n >> k;
	for(int i = 1;i <= n;i++) cin >> a[i];
	ll ans = 0, l = 0, r = 1e18/k;
	while(l <= r) {
		ll mid = (l+r) >> 1, sum = 0;
		for(int i = 1;i <= n;i++) sum += min(a[i], mid);
		//ans记录满足条件的答案，l和r用于缩小边界
		if(sum >= mid*k) ans = mid, l = mid+1;
		else r = mid-1;
	}
	cout << ans;
    return 0;
}
