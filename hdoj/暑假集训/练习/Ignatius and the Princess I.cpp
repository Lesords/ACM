#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
int n,m,map[105][105],ans,vis[105][105];
struct node {
	int x,y,step;
	friend bool operator < (node a, node b) {
		return a.step>b.step;
	}
};
node way[105][105];
bool bfs() {
	priority_queue<node> q;
	q.push(node{0,0,0});
	int next[4][2]={0,1,1,0,0,-1,-1,0};
	node tmp;
	memset(way,0,sizeof(way));
	while(!q.empty()) {
		tmp=q.top();
		q.pop();
		if(tmp.x==n-1&&tmp.y==m-1) {
			ans=tmp.step;
			return true;
		}
		for(int i=0;i<4;i++) {
			int tx=tmp.x+next[i][0];
			int ty=tmp.y+next[i][1];
			if(tx<0||tx>n-1||ty<0||ty>m-1) continue;
			if(map[tx][ty]==-1||vis[tx][ty]) continue;
			if(!map[tx][ty]) {
				q.push(node{tx,ty,tmp.step+1});
				way[tx][ty].step=tmp.step+1;
			}
			else {
				q.push(node{tx,ty,tmp.step+1+map[tx][ty]});
				way[tx][ty].step=tmp.step+1+map[tx][ty];
			}
			vis[tx][ty]=1;
			way[tx][ty].x=tmp.x;
			way[tx][ty].y=tmp.y; 
		}
	} 
	return false;
}
void print_path() {
	priority_queue<node> path;
	int tx,ty,time=1;
	tx=n-1,ty=m-1;
	for(int i=ans;i>=0;i--) {
		node tmp;
		tmp.x=way[tx][ty].x;
		tmp.y=way[tx][ty].y;
		tmp.step=way[tx][ty].step;
		path.push(tmp);
		tx=tmp.x;
		ty=tmp.y;
		if(tx==0&&ty==0) break;
	}
	path.push(node{n-1,m-1,ans});
	while(!path.empty()) {
		node tmp1,tmp2;
		tmp1=path.top();
		path.pop();
		tmp2=path.top();
		if(!map[tmp2.x][tmp2.y]) {
			printf("%ds:(%d,%d)->(%d,%d)\n",time++,tmp1.x,tmp1.y,tmp2.x,tmp2.y);
		}
		else {
			printf("%ds:(%d,%d)->(%d,%d)\n",time++,tmp1.x,tmp1.y,tmp2.x,tmp2.y);
			for(int i=1;i<=map[tmp2.x][tmp2.y];i++) {
				printf("%ds:FIGHT AT (%d,%d)\n",time++,tmp2.x,tmp2.y);
			}
		}
		if(tmp2.x==n-1&&tmp2.y==m-1) break;
	} 
}
int main() {
	char ch;
	while(cin>>n>>m) {
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				cin>>ch;
				if(ch=='.') map[i][j]=0;
				else if(ch=='X') map[i][j]=-1;
				else map[i][j]=ch-'0';
			}
		}
		memset(vis,0,sizeof(vis));
		if(bfs()) {
			cout<<"It takes "<<ans<<" seconds to reach the target position, ";
			cout<<"let me show you the way."<<endl;
			print_path();
		}
		else cout<<"God please help our poor hero."<<endl;
		cout<<"FINISH"<<endl;
	}
	return 0;
} 
