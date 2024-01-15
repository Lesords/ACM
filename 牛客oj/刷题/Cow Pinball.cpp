#include<iostream>//ac 紫书的数塔（HDU-2084）
#include<algorithm>
using namespace std;
int a[30][30],dp[30][30];
int main() {
	int t;
	cin>>t;
	for(int i = 1;i <= t;i++) {
		for(int j = 1;j <= i;j++) cin>>a[i][j];
	}
	for(int i = 1;i <= t;i++) dp[t][i] = a[t][i];
	for(int i = t-1;i >= 1;i--) {//自底向上优化
		for(int j = 1;j <= i;j++) {
			dp[i][j] = a[i][j] + max(dp[i+1][j],dp[i+1][j+1]);
		}
	}
	cout<<dp[1][1]<<endl;
	return 0;
} 
