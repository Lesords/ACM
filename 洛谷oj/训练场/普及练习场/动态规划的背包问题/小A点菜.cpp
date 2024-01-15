#include<iostream>//ac
#include<algorithm>
using namespace std;
int a[105],dp[10005];
//dp[i] 表示花完i元的方案数
int main() {
	int n,m;
	cin>>n>>m;
	for(int i = 1;i <= n;i++) cin>>a[i];
	dp[0] = 1;//花0元只有1种，就是不花
	for(int i = 1;i <= n;i++) {
		for(int j = m;j >= a[i];j--)
			dp[j] += dp[j-a[i]];
			//每个j都有买a[i]的一种可能性
	}//各类方案数累计
	cout<<dp[m]<<endl;
	return 0;
}
