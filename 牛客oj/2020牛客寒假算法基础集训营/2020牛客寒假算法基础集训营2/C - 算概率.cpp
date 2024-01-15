#include<iostream>//ac
#define ll long long
using namespace std;
const int MOD = 1e9+7;
const int MAXN = 2050;
ll p[MAXN],dp[MAXN][MAXN];//会爆int，需要ll
//dp[i][j] 代表i题中答对j题的概率
//i题中答对j题 = (i-1)题中答对j题且i题错了 + (i-1)题中答对(j-1)题且i题对了
//则 dp[i][j] = dp[i-1][j]*(MOD+1-p[i]) + dp[i-1][j-1]*p[i]

//(a/b)%MOD = p[i] => b*p[i]%MOD = a
//设b为1(a为概率值)，则有 p[i] = a + MOD => a = p[i] - MOD
//错误率：1-a = 1+MOD-p[i]

//也可把(a/b)当成一个整体(概率值)，则有 p[i]%MOD = a/b
//=> p[i] = a/b + MOD  =>  a/b = p[i] - MOD

//结果都是 正确概率 = 模后值(p[i]) - 模(MOD)
//则i题的正确率为 p[i],错误率为 (MOD+1-p[i])

int main() {
	int n;
	cin>>n;
	for(int i = 1;i <= n;i++) cin>>p[i];
	dp[0][0] = 1;//0题中答对0题为1，其他都为0
	for(int i = 1;i <= n;i++) {
		dp[i][0] = dp[i-1][0]*(MOD+1-p[i])%MOD;//先初始化0题
		for(int j = 1;j <= i;j++) {//然后计算剩余可能性
			dp[i][j] = dp[i-1][j]*(MOD+1-p[i])%MOD + dp[i-1][j-1]*(p[i]%MOD);
			dp[i][j] %= MOD;
		}
	}
	for(int i = 0;i <= n;i++) {
		if(i!=0) cout<<' ';
		cout<<dp[n][i];
	}
	return 0;
}
