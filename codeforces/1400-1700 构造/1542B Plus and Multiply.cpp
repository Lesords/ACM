// Problem: B. Plus and Multiply
// Contest: Codeforces - Codeforces Round #729 (Div. 2)
// URL: https://codeforces.ml/problemset/problem/1542/B
// Memory Limit: 512 MB
// Time Limit: 3000 ms
// 
// Author：Lese
// Time：2021-11-12 10:45:31

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

//题解：构造题
//对于 a = 1的时候有： x + yb = n  =>		y = (n-x)/b		=>	y = (n-1)/b
//此时判断 n-1 是否为b的倍数即可
//对于 a != 1的情况：
//由于对于 +b的操作其实就是就相当于两数modb的值一致
//那么只需要对 *a的操作进行枚举
//枚举出小于n的范围内，所有的a幂次方，判断与b的取模是否与n相等即可

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
const double pi = acos(double(-1));
int main() {
	fast;
	int t;
	cin >> t;
	for(int i = 1;i <= t;i++) {
		int n, a, b;
		cin >> n >> a >> b;
		if(a==1) {
			cout << ((n-1)%b==0?"Yes\n":"No\n");
		}
		else {
			ll val = 1;//注意val要从1开始！！！
			bool ok = 0;
			while(val <= n) {
				//两数取模一致，说明 val+?b = n
				if(val%b==n%b) {
					ok = 1;
					break;
				}
				val *= a;
			}
			cout << (ok?"Yes\n":"No\n");
		}
	}
    return 0;
}
