#include<iostream>//ac
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
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
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int MAXN = 2e5+5;
const int MOD = 1e9+7;
int dp[MAXN];//dp[i]：表示以i为结尾（包括i）的序列数量
int main() {
	string s;
	cin>>s;
	int len = s.size();
	dp[0] = 1;//表示空字符串时，出现了一次
	//dp[1]不赋值，对于dp[2](实际为0位置) 的值是从0才有贡献的，与1无关（偏移2）
	//而后面位置，只需要和 dp[0] 匹配 组成单个字符即可（多个1会重复）
	for(int i = 0;i < len;i++) {
		//倒着查找，找到重复的，直接结束
		for(int j = i;j >= 0;j--) {//因为整体偏移了两个位置，所以j从i开始即可
			dp[i+2] = (dp[i+2]+dp[j])%MOD;
			if(s[j-1]==s[i]) break;//下一个重复了，直接结束
		}
	}
	ll ans = 0;
	for(int i = 2;i < len+2;i++) {
		ans = (ans+dp[i])%MOD;
	}
	cout<<ans;
    return 0;
}