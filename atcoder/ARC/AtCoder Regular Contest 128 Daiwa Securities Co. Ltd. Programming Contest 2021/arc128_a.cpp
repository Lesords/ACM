// Problem: A - Gold and Silver
// Contest: AtCoder - Daiwa Securities Co. Ltd. Programming Contest 2021（AtCoder Regular Contest 128）
// URL: https://atcoder.jp/contests/arc128/tasks/arc128_a
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Author：Lese
// Time：2021-10-16 20:01:55

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
#include<assert.h>
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

//题解：首先，需要知道，一天中交易两次相当于没有交易
//其次，对于x和y天交易，
//可以相当于 x和x+1对应交易， x+1和x+2对应交易，··· x+3和y对应交易
//也就是说，每个相邻的都判断过去，因为重复位置如果需要都交易的话会抵消（所以可用异或）
//那么对于需要交易的情况，肯定是 当前值大于下一天的值

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
const double pi = acos(double(-1));
int a[MAXN], ans[MAXN];
int main() {
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
	}
	for(int i = 1;i < n;i++) {//逐个判断，重复位置会抵消
		if(a[i] > a[i+1]) {//当前值大于下一天的值，才需要交易
			ans[i] ^= 1;
			ans[i+1] ^= 1;
		}
	}
	for(int i = 1;i <= n;i++) {
		cout << ans[i] << " ";
	}
    return 0;
}
