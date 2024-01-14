// Problem: B - Balls of Three Colors
// Contest: AtCoder - Daiwa Securities Co. Ltd. Programming Contest 2021（AtCoder Regular Contest 128）
// URL: https://atcoder.jp/contests/arc128/tasks/arc128_b
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Author：Lese
// Time：2021-10-16 20:26:25

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

//题解：x与y需要满足同模3的结果相等，才可以

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
const double pi = acos(double(-1));
int main() {
    int t;
    cin>>t;
    while(t--) {
    	int a[4];
    	for(int i = 1;i <= 3;i++) cin >> a[i];
    	sort(a+1, a+4);
    	int ans = INF;
    	if(a[1]%3==a[2]%3) {
    		ans = min(ans, a[1] + (a[2]-a[1]));
    	}
    	if(a[2]%3==a[3]%3) {
    		ans = min(ans, a[2] + (a[3]-a[2]));
    	}
    	if(a[1]%3==a[3]%3) {
    		ans = min(ans, a[1] + (a[3]-a[1]));
    	}
    	if(ans == INF) ans = -1;
    	cout << ans << "\n";
    }
    return 0;
}
