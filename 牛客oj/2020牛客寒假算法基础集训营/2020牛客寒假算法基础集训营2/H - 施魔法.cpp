#include<iostream>//ac
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;

//题解：选择k个元素，计算极差和，选择无限制则可先排序
//可以得到每次操作有两个选择
//A：将当前位改为max值，替换前一位（k+n个）
//B：以当前位为第k个，往前（k-1）个为一组，再加上之前的dp[i-k]
//dp[i] = min(A, B)

const int MAXN = 3e5+5;
int a[MAXN],dp[MAXN];//dp[i]为i位消耗的最小值
int main() {
	int n,k;
	cin>>n>>k;
	for(int i = 1;i <= n;i++) cin>>a[i],dp[i] = INF;
	sort(a+1,a+n+1);//排序！！！
	dp[k] = a[k]-a[1];//初始化第一个状态，至少k个则从k开始
	for(int i = k+1;i <= n;i++) {//从k+1开始
		dp[i] = min(dp[i-1]-a[i-1]+a[i],dp[i-k]+a[i]-a[i-k+1]);
	}//A为一组，B为两组
	cout<<dp[n];
	return 0;
}
