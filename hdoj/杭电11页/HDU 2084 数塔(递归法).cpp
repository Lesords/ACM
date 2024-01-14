#include<iostream>//�ݹ鷨ac
#include<cstring>
#include<algorithm>
using namespace std;
int a[105][105],dp[105][105],n;
int solve(int i,int j) {
	if(dp[i][j]>=0) return dp[i][j];
	return dp[i][j] = a[i][j] + (i==n?0:max(solve(i+1,j),solve(i+1,j+1)));
}
int main() {
	int T;
	cin>>T;
	while(T--) {
		cin>>n;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=i;j++)
				 cin>>a[i][j];
		memset(dp,-1,sizeof(dp));
		cout<<solve(1,1)<<endl;
	}
	return 0;
} 
