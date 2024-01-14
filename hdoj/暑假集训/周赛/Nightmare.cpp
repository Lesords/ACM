#include<iostream>
#include<cstring>
#include<queue> 
#define INF 99999999
using namespace std;
int map[105][105],ans,vis[105][105],sx,sy,ex,ey,n,m;
struct node {
	int x,y,step,time;
};
bool bfs(int x, int y) {
	queue<node> q;
	q.push(node{x,y,0,6});//�ṹ��ļ��� 
	int next[4][2]={1,0,0,1,-1,0,0,-1};
	while(!q.empty()) {
		node tmp=q.front();
		q.pop();
		if(tmp.x==ex&&tmp.y==ey) {
			ans=tmp.step;
			return true;
		}
		if(tmp.time<=1) continue;//���˵�������һ���㣬ը��Ϊ������ 
		for(int i=0;i<4;i++) {
			int tx=tmp.x+next[i][0];
			int ty=tmp.y+next[i][1];
			if(tx<1||tx>n||ty<1||ty>m||!map[tx][ty]||vis[tx][ty]) continue;
			if(map[tx][ty]==4) {
				vis[tx][ty]=1;//ֻ�������ը����λ��
				q.push(node{tx,ty,tmp.step+1,6});
			}
			else q.push(node{tx,ty,tmp.step+1,tmp.time-1});
		}
	}
	return false;
}
int main() {
	int t;
	cin>>t;
	while(t--) {
		cin>>n>>m;
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++) {
				cin>>map[i][j];
				if(map[i][j]==2) sx=i,sy=j;//��ʼ�� 
				if(map[i][j]==3) ex=i,ey=j;//�յ� 
			}
		if(bfs(sx,sy)) cout<<ans<<endl;
		else cout<<"-1"<<endl;
	}
	return 0;
} 
