#include<iostream>//ac
using namespace std;
char a[105][105];
int nextt[9][2] = {-1,-1,-1,0,-1,1,0,-1,0,1,1,-1,1,0,1,1};
int n,m;
char count_mine(int x, int y) {
	int cnt = 0;
	for(int i = 0;i < 9;i++) {//9个方向
		int tx = x + nextt[i][0];
		int ty = y + nextt[i][1];
		if(tx<1||tx>n||ty<1||ty>m) continue;//越界
		if(a[tx][ty] == '*') cnt++;
	}
	return cnt + '0';//返回为字符
}
int main() {
	cin>>n>>m;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++) cin>>a[i][j];
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= m;j++)
			if(a[i][j] == '?') a[i][j] = count_mine(i,j);
	}
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= m;j++) cout<<a[i][j];
		cout<<endl;
	}
	return 0;
}
