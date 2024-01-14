// Problem: E - LEQ
// Contest: AtCoder - AtCoder Beginner Contest 221
// URL: https://atcoder.jp/contests/abc221/tasks/abc221_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Author：Lese
// Time：2021-10-09 15:30:14

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
#define lowbit(x) (x)&(-x)
using namespace std;

//题解：树状数组+离散化
//首先需要知道，对于首尾为i和j的情况
//对应的子序列数量为：2^(j-i-1) = 2^(j-1) / 2^i

//所以我们可以知道，如果需要计算当前位置可以匹配的子序列数
//可以提前记录前面 所有小于当前值 的位置的对应值总和 （单个值为1/2^i）
//所以可以从前往后用树状数组来记录 所有出现过的值 的对应值总和
//那么每遍历到一个位置，只需要求 对应值范围的总和 * 当前贡献（2^(i-1)）

const int MAXN = 3e5+5;
const int MOD = 998244353;
const double pi = acos(double(-1));
int a[MAXN], siz;
ll tree[MAXN];
vector<int> all;
int getV(int val) {
	return lower_bound(all.begin(), all.end(), val) - all.begin()+1;
}
ll poww(ll a, ll b) {
	ll ans = 1;
	while(b) {
		if(b&1) ans = (ans*a)%MOD;
		a = (a*a)%MOD;
		b >>= 1;
	}
	return ans%MOD;
}
ll ask(int pos) {
	ll ans = 0;
	while(pos) {
		ans = (ans+tree[pos])%MOD;
		pos -= lowbit(pos);
	}
	return ans%MOD;
}
void add(int pos, ll val) {
	while(pos <= siz) {
		tree[pos] = (tree[pos]+val)%MOD;
		pos += lowbit(pos);
	}
}
int main() {
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
		all.push_back(a[i]);
	}
	sort(all.begin(), all.end());
	all.erase(unique(all.begin(), all.end()), all.end());
	siz = all.size();//离散化操作
	for(int i = 1;i <= n;i++) {
		a[i] = getV(a[i]);//将对应值修改为离散后的值
	}
	ll div = poww(2, MOD-2), ans = 0;//div为 1/2 的逆元
	for(int i = 1;i <= n;i++) {
		ans = (ans + ask(a[i]) * poww(2, i-1))%MOD;
		add(a[i], poww(div, i));
	}
	cout << ans;
    return 0;
}
