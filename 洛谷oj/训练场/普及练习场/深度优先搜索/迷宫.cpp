#include<iostream>//ac
using namespace std;
int n,m,t,sx,sy,ex,ey,ans;
int nextt[4][2] = {1,0,0,1,-1,0,0,-1};
int book[10][10];
void dfs(int x,int y) {
	if(x==ex&&y==ey) {//到达终点，方案数++
		ans++;return;
	}
	for(int i = 0;i < 4;i++) {
		int tx = x + nextt[i][0];
		int ty = y + nextt[i][1];
		if(tx<1||tx>n||ty<1||ty>m) continue;//越界
		if(book[tx][ty]) continue;//障碍物或已走过
		book[tx][ty] = 1;
		dfs(tx,ty);
		book[tx][ty] = 0;//需还原
	}
}
int main() {
	cin>>n>>m>>t>>sx>>sy>>ex>>ey;
	int a,b;
	book[sx][sy] = 1;//标记起点！！！
	while(t--) {
		cin>>a>>b;
		book[a][b] = 1;//标记障碍物
	}
	dfs(sx,sy);
	cout<<ans<<endl;
	return 0;
}
