#include<iostream>//ac
#define ll long long
using namespace std;
ll dp[30][30];//�𰸻ᱬint
int nextt[8][2] = {1,2,2,1,2,-1,1,-2,-1,-2,-2,-1,-2,1,-1,2};
int main() {//������ߵİ˸�����
	int n,m,h1,h2;
	cin>>n>>m>>h1>>h2;
	dp[h1][h2] = -1, dp[0][0] = 1;//���Ϊ1
	for(int i = 0;i < 8;i++) {//������ߵĵ㶼Ϊ-1�������ߣ�
		int tx = h1+nextt[i][0];
		int ty = h2+nextt[i][1];
		if(tx<0||tx>n||ty<0||ty>m) continue;//Խ��
		dp[tx][ty] = -1;
	}
	for(int i = 0;i <= n;i++) {
		for(int j = 0;j <= m;j++) {
			if(dp[i][j]==-1) continue;//������
			if(dp[i+1][j]!=-1) dp[i+1][j] += dp[i][j];//��
			if(dp[i][j+1]!=-1) dp[i][j+1] += dp[i][j];//��
		}
	}
	cout<<dp[n][m]<<endl;
	return 0;
}
