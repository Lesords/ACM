#include<iostream>//递推法ac
#include<algorithm>
#include<cstring>
using namespace std;
int a[105][105],dp[105][105];
int main() {
	int T,n;
	cin>>T;
	while(T--) { 
		cin>>n;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=i;j++) 
				cin>>a[i][j];
		for(int i=1;i<=n;i++) dp[n][i] = a[n][i];//预处理dp最下层数据
		for(int i=n-1;i>=1;i--)
			for(int j=1;j<=i;j++)//a[i][j] !!! dp[i][j]为零
				dp[i][j] = a[i][j] + max(dp[i+1][j],dp[i+1][j+1]);
		cout<<dp[1][1]<<endl;
	}
	return 0;
} 
