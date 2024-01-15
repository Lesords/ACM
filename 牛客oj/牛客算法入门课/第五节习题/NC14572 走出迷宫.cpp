#include<iostream>//ac
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int MAXN = 505;
char map[MAXN][MAXN];
int vis[MAXN][MAXN],n,m,sx,sy,ex,ey;
int nextt[4][2] = {1,0,0,1,-1,0,0,-1};
struct node{
	int x,y;
};
bool bfs() {
	queue<node> q;
	q.push(node{sx,sy});//起点
	memset(vis,0,sizeof(vis));//多组输入需初始化vis
	node tmp;
	while(!q.empty()) {
		tmp = q.front();q.pop();
		if(tmp.x==ex&&tmp.y==ey) return 1;//可以走出
		for(int i = 0;i < 4;i++) {
			int tx = tmp.x + nextt[i][0];
			int ty = tmp.y + nextt[i][1];
			//边界 墙 已走过
			if(tx<1||tx>n||ty<1||ty>m) continue;
			if(vis[tx][ty]||map[tx][ty]=='#') continue;
			vis[tx][ty] = 1;
			q.push(node{tx,ty});
		}
	}
	return 0;//不可以走出
}
int main() {
	while(cin>>n>>m) {
		for(int i = 1;i <= n;i++) {
			for(int j = 1;j <= m;j++) {
				cin>>map[i][j];
				//保存对应起点和终点
				if(map[i][j]=='S') sx=i,sy=j;
				if(map[i][j]=='E') ex=i,ey=j;
			}
		}
		if(bfs()) cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}
