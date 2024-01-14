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

//题解：线性dp
//需要注意，题目要求前面为nunhehheh，后面为a（a的数量不能为0）
//也就是说中间不能有其他字符
//那么考虑对于每个位置判断是否有多少个nunhehheh，然后乘上后面的a对其的贡献
//可以利用前缀和来记录对应a的数量
//由于a的数量不能为0个，那么可以计算所有可能性，然后减去为空的情况即可
//即 2^num - 1
//线性dp分析过程：
//状态：dp[i][j] 表示在给字符串中从1到i位置匹配到j位置字符的次数
//转移方程：
// dp[i][0] = dp[i-1][0] + (s[i] == ss[0])	注意括号，运算优先级
// dp[i][j] = dp[i-1][j] + (s[i] == ss[j]) * dp[i-1][j-1] 其中 1 <= j <= 7
// dp[i][8] = (s[i] == ss[8]) * dp[i-1][7]
//注意：除了最后一个位置，其他都需要累加前面的状态
//因为我们只需要计算 匹配到当前位置的数量 乘上 对应后面a的贡献

const int MAXN = 1e5+5;
const int MOD = 998244353;
const double pi = acos(double(-1));
ll dp[MAXN][10], pre[MAXN];
int len;
char s[MAXN];
ll poww(ll a, ll b) {//a^b
	if(b<0) return 0;
	ll ans = 1;
	while(b) {
		if(b&1) ans = (ans*a)%MOD;
		a = (a*a) %MOD;
		b >>= 1;
	}
	return ans%MOD;
}
int main() {
	fast;//加速
	string ss = "nunhehheh";
    int t;
    cin>>t;
    while(t--) {
    	cin>>(s+1);
    	memset(dp, 0, sizeof(dp));//初始化
    	len = strlen(s+1);
    	pre[0] = 0;
    	for(int i = 1;i <= len;i++) {//计算a出现的数量
    		pre[i] = pre[i-1] + (s[i]=='a');
    	}
    	ll ans = 0,flag = 0;
    	for(int i = 1;i <= len;i++) {//遍历所有位置
    		dp[i][0] = (dp[i-1][0] + (s[i]=='n')) %MOD;
    		for(int j = 1;j < 9;j++) {
    			if(j==8) {//注意最后一个位置不需要累加（会重复）
    				dp[i][j] = ((s[i]==ss[j]) * dp[i-1][j-1]) %MOD;
    			}
    			else dp[i][j] = (dp[i-1][j] + (s[i]==ss[j]) * dp[i-1][j-1]) %MOD;
    		}
    		ll num = pre[len] - pre[i];//当前位置后面的a数量
    		ll one = ((dp[i][8] * (poww(2, num)-1)) % MOD)%MOD;
    		//当前匹配数位 dp[i][8]，a的贡献为 poww(2, num) - 1
    		ans = (ans+one)%MOD;		
    	}
    	cout << ans << "\n";
    }
    return 0;
}
