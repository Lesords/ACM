// Problem: D. Say No to Palindromes
// Contest: Codeforces - Educational Codeforces Round 112 (Rated for Div. 2)
// URL: https://codeforces.ml/problemset/problem/1555/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Author：Lese
// Time：2021-09-29 11:20:52

#include<iostream>//ac
#include<cstring>
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

//题解：由于只有三个字符 a b c
//由于不能满足两个大小的字符串为回文串，所以 s[i] != s[i-1]
//由于不能为长度为3的回文串，所以 s[i] != s[i-2]
//那么可以有 s[i] == s[i-3]
//则 对于不满足回文串的字符即为这三个字符的全排列
//例如： abcabcabc...
//对于本题则有，构造abc的所有全排列（6种）
//然后利用前缀和来记录对应位置需要修改的次数

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
const double pi = acos(double(-1));
int num[6][MAXN];//num[i][j]：第i中全排列中, 从1到j位置需要修改的次数和
int main() {
	fast;
	string s;
	int n, m;
	cin>>n>>m>>s;
	char a[4] = {'a', 'b', 'c'};//初始化全排列
	int cur = 0;//初始化下标
	do {
		for(int i = 0;i < s.size();i++) {
			//由于对应区间从1开始，所以需要num数组整体偏移一位
			num[cur][i+1] = num[cur][i] + (s[i]!=a[i%3]);//从1开始记录
			// num[cur][i] = num[cur][i-1] + (s[i]!=a[i%3]);//从0开始记录
		}
		cur++;
	} while(next_permutation(a, a+3));//获取下一个排列
	while(m--) {
		int l, r;
		cin>>l>>r;
		int ans = INF;
		for(int i = 0;i < 6;i++) {//取6种全排列中最小的值即为结果
			ans = min(ans, num[i][r] - num[i][l-1]);
		}
		cout<<ans<<"\n";
	}
    return 0;
}
