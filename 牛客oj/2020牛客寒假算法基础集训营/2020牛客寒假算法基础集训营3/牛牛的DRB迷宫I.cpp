#include<iostream>//ac
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int MOD = 1e9+7;
int ans[55][55];
char map[55][55];
int main() {
	int n,m;
	cin>>n>>m;
	ans[1][1] = 1;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++) cin>>map[i][j];
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= m;j++) {
			if(map[i][j]=='D') {//Èý´óÀà£¡£¡£¡
				if(i+1<=n) ans[i+1][j] = (ans[i+1][j]+ans[i][j])%MOD;
			}
			else if(map[i][j]=='R') {
				if(j+1<=m) ans[i][j+1] = (ans[i][j+1]+ans[i][j])%MOD;
			}
			else {
				if(j+1<=m) ans[i][j+1] = (ans[i][j+1]+ans[i][j])%MOD;
				if(i+1<=n) ans[i+1][j] = (ans[i+1][j]+ans[i][j])%MOD;
			}
		}
	}
	cout<<ans[n][m]%MOD;
	return 0;
}
