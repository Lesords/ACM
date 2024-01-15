#include<cstdio>//ac
#include<algorithm>
#define INF 0x7f3f3f3f
//INF不够大！！！
#define ll long long
using namespace std;
const int MAXN = 2e5+5;
ll dp[MAXN][2];
//dp[i][0]:i位数字 没有 加1的最小总代价
//dp[i][1]:i位数字 有 加1的最小总代价

int a[MAXN],b[MAXN];
int main() {
	int n;
	scanf("%d",&n);
	for(int i = 1;i <= n;i++) {
		scanf("%d%d",&a[i],&b[i]);
		dp[i][0] = dp[i][1] = INF;//初始化为INF
		//dp需要求最小总代价，所以需要初始化为INF
	}
	dp[1][1] = b[1],dp[1][0] = 0;//初始化第一个状态
	//加1和不加1的值
	for(int i = 2;i <= n;i++) {
		//判断总共有4种情况
		//当前不加1：前加1，前不加1
		//当前加1  ：前不加1，前加1
		if(a[i]!=a[i-1]) dp[i][0] = min(dp[i][0],dp[i-1][0]);
		if(a[i]!=a[i-1]+1) dp[i][0] = min(dp[i][0],dp[i-1][1]);
		if(a[i]+1!=a[i-1]) dp[i][1] = min(dp[i][1],dp[i-1][0]+b[i]);
		if(a[i]+1!=a[i-1]+1) dp[i][1] = min(dp[i][1],dp[i-1][1]+b[i]);
		//当前加1时需要加上对应的代价 b[i]
	}
	printf("%lld",min(dp[n][1],dp[n][0]));
	return 0;
}
