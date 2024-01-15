// Problem: C. Sequence
// Contest: Codeforces - Codeforces Beta Round #13
// URL: https://codeforces.ml/problemset/problem/13/C
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// 
// Author：Lese
// Time：2021-11-09 16:03:44

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

//题意：给定对应数列，可以对每个数进行+1或者-1操作
//求需要多少操作次数使得序列为非下降序列
//题解：将所有数字从小到大排序
//那么原序列需要修改为对应有序序列b中的值
//令 dp[i][j] 为 前i个位置的值以b[j]为末尾所需要花费的最小值
//由于i只与前一个位置i-1有关，所以可以滚动掉第一维

//那么对应的 dp[j] 表示为前i个以b[j]为末尾的最小操作次数
//注意当前位置i可以修改为 b[j]，也可以直接以前j-1中任意一个为末尾

const int MAXN = 5e3+5;
const int MOD = 1e9+7;
const double pi = acos(double(-1));
ll dp[MAXN];//注意longlong！！！
int a[MAXN], b[MAXN];
int main() {
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b+1, b+n+1);//排序
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) {
			//第i个的值修改为 b[j] 的
			dp[j] += abs(a[i]-b[j]);
			//如果以 b[1] 为末尾，那么所有位置都需要操作，即 += abs(a[i]-b[j])
			if(j > 1) {
				//对于每个位置i都有两种选择：
				//1. 修改为b[j]值
				//2. 不修改为b[j]值，即为j前面的值
				dp[j] = min(dp[j], dp[j-1]);//dp[j-1]中包括了对第i位置的操作
			}
		}
	}
	cout << dp[n];
    return 0;
}
