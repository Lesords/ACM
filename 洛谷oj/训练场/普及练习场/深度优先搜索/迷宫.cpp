#include<iostream>//ac
using namespace std;
int n,m,t,sx,sy,ex,ey,ans;
int nextt[4][2] = {1,0,0,1,-1,0,0,-1};
int book[10][10];
void dfs(int x,int y) {
	if(x==ex&&y==ey) {//�����յ㣬������++
		ans++;return;
	}
	for(int i = 0;i < 4;i++) {
		int tx = x + nextt[i][0];
		int ty = y + nextt[i][1];
		if(tx<1||tx>n||ty<1||ty>m) continue;//Խ��
		if(book[tx][ty]) continue;//�ϰ�������߹�
		book[tx][ty] = 1;
		dfs(tx,ty);
		book[tx][ty] = 0;//�軹ԭ
	}
}
int main() {
	cin>>n>>m>>t>>sx>>sy>>ex>>ey;
	int a,b;
	book[sx][sy] = 1;//�����㣡����
	while(t--) {
		cin>>a>>b;
		book[a][b] = 1;//����ϰ���
	}
	dfs(sx,sy);
	cout<<ans<<endl;
	return 0;
}
