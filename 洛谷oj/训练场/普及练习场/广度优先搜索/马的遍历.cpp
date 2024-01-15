#include<iostream>//ac
#include<cstdio>
#include<queue>
using namespace std;
const int MAXN = 405;
int map[MAXN][MAXN],vis[MAXN][MAXN];
int n,m,s,e;//马可以走8个方向
int nextt[8][2] = {1,2,2,1,1,-2,2,-1,-2,1,-1,2,-1,-2,-2,-1};
struct node {
	int x,y,step;
};
void bfs(int x,int y) {
	queue<node> q;
	q.push(node{x,y,0});//起点步数为0
	node tmp;
	while(!q.empty()) {
		tmp = q.front();q.pop();
		for(int i = 0;i < 8;i++) {
			int tx = tmp.x + nextt[i][0];
			int ty = tmp.y + nextt[i][1];
			if(tx<1||tx>n||ty<1||ty>m) continue;//越界
			if(vis[tx][ty]) continue;//已走过
			vis[tx][ty] = 1;//标记当前位置
			map[tx][ty] = tmp.step+1;//保存当前步数
			q.push(node{tx,ty,tmp.step+1});
		}
	}
}
int main() {
	cin>>n>>m>>s>>e;
	bfs(s,e);//从起点bfs
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= m;j++) {
			if(i==s&&j==e) cout<<"0    ";//起点为0，不能到为-1
			else printf("%-5d",(map[i][j]?map[i][j]:-1));
		}
		cout<<endl;
	}
	return 0;
}
