#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
struct road {
	int x,y,step;
	friend bool operator < (road a,road b) {
		return a.step>b.step;//先出小的 
	}
};
int m,n,map[25][25],book[25][25];
int bfs(int sx,int sy,int ex,int ey) {
	priority_queue<road> q;
	q.push(road{sx,sy,0});
	road tmp;
	int next[4][2]={1,0,0,1,-1,0,0,-1};//0 2为上下方向 
	while(!q.empty()) {
		tmp=q.top(); q.pop();
		if(tmp.x==ex&&tmp.y==ey) break;
		for(int i=0;i<4;i++) {
			int tx=tmp.x+next[i][0];
			int ty=tmp.y+next[i][1];
			if(tx<1||tx>m||ty<1||ty>n) continue;
			if(book[tx][ty]||map[tx][ty]==-1) continue;
			if(!map[tx][ty]) {//普通区域 
				q.push(road{tx,ty,tmp.step+1});
				book[tx][ty]=1;//不标记梯子！！！ 
				continue;
			}
			int ttx=tx+next[i][0];
			int tty=ty+next[i][1];
			if(i==0||i==2){//上或下
				if((map[tx][ty]+tmp.step)%2)//1为| 0为- 
					q.push(road{ttx,tty,tmp.step+1});
				else q.push(road{ttx,tty,tmp.step+2});
			}
			else {//左或右
				if((map[tx][ty]+tmp.step)%2) 
					q.push(road{ttx,tty,tmp.step+2});
				else q.push(road{ttx,tty,tmp.step+1});
			}
			book[ttx][tty]=1;
		}
	}
	return tmp.step;
}
int main() {
	while(cin>>m>>n) {
		memset(book,0,sizeof(book));
		int sx,sy,ex,ey;
		char ch;
		for(int i=1;i<=m;i++) {
			for(int j=1;j<=n;j++) {
				cin>>ch;
				if(ch=='.') map[i][j]=0;
				else if(ch=='*') map[i][j]=-1;
				else if(ch=='|') map[i][j]=1;
				else if(ch=='-') map[i][j]=2;
				else if(ch=='S') sx=i,sy=j,map[i][j]=0;
				else if(ch=='T') ex=i,ey=j,map[i][j]=0;
			}
		}
		book[sx][sy]=1;
		cout<<bfs(sx,sy,ex,ey)<<endl;
	}
	return 0;
}
