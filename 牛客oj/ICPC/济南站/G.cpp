// Problem: Xor Transformation
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/23862/G
// Memory Limit: 524288 MB
// Time Limit: 2000 ms
// 
// Author：Lese
// Time：2021-11-11 18:44:02

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
const int MAXN = 2e5+5;
const int MOD = 1e9+7;
const double pi = acos(double(-1));
int main() {
	ll x, y;
	cin >> x >> y;
	ll tmp = y, val = 0, i = 1;
	cout << "2\n";//最多只需要两次
	//y中有的，x中没有的，全部添加到x中
	//然后在x中删除y中没有的
	while(i <= y) {
		if((i&y) && (x&i)==0) {
			val += i;
			x += i;
		}
		i <<= 1;
	}
	cout << val;
	i = 1, val = 0;
	while(i <= x) {
		if((i&x) && (i&y)==0) {
			val += i;
		}
		i <<= 1;
	}
	cout << " " << val;
    return 0;
}
