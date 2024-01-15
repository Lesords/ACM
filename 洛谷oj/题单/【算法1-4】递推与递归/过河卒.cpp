#include<iostream>//ac
#define ll long long
using namespace std;
ll dp[30][30];//答案会爆int
int nextt[8][2] = {1,2,2,1,2,-1,1,-2,-1,-2,-2,-1,-2,1,-1,2};
int main() {//马可以走的八个方向
	int n,m,h1,h2;
	cin>>n>>m>>h1>>h2;
	dp[h1][h2] = -1, dp[0][0] = 1;//起点为1
	for(int i = 0;i < 8;i++) {//马和马走的点都为-1（不可走）
		int tx = h1+nextt[i][0];
		int ty = h2+nextt[i][1];
		if(tx<0||tx>n||ty<0||ty>m) continue;//越界
		dp[tx][ty] = -1;
	}
	for(int i = 0;i <= n;i++) {
		for(int j = 0;j <= m;j++) {
			if(dp[i][j]==-1) continue;//不可走
			if(dp[i+1][j]!=-1) dp[i+1][j] += dp[i][j];//下
			if(dp[i][j+1]!=-1) dp[i][j+1] += dp[i][j];//右
		}
	}
	cout<<dp[n][m]<<endl;
	return 0;
}
