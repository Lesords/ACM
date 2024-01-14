#include<iostream>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;
struct box_move {//箱子
	int x,y,wx,wy,step;//x y 为箱子当前位置 wx wy 为工人当前位置
	friend bool operator <(box_move a,box_move b) {
		return a.step>b.step;
	}
};
struct work {//工人
	int x,y;//只需要判断是否可以到达指定位置，无需step 
};
int map[8][8],book[8][8],vis[8][8],n,m,ex,ey;
int bfs_move(int x,int y,int nx,int ny) {//x,y为搬运工的目的位置
	queue<work> man;
	man.push(work{nx,ny});//搬运工初始位置
	int next[4][2]={1,0,0,1,-1,0,0,-1};//四个方向 
	while(!man.empty()) {
		work tmp;
		tmp = man.front();man.pop();
		if(tmp.x==x&&tmp.y==y) return false;//可以到达 
		for(int i=0;i<4;i++) {
			int tx = tmp.x + next[i][0];
			int ty = tmp.y + next[i][1];
			if(tx<1||tx>m||ty<1||ty>n) continue;//越界 
			if(map[tx][ty]==-1||book[tx][ty]) continue;//墙或已走过 
			man.push(work{tx,ty});
			book[tx][ty]=1;//标记走过的格子 
		}
	}
	return true;
}
int bfs(int sx,int sy,int wx,int wy) {//箱子
	priority_queue<box_move> q;
	q.push(box_move{sx,sy,wx,wy,0});
	int next[4][2]={1,0,0,1,-1,0,0,-1};
	while(!q.empty()) {
		box_move tmp;
		tmp = q.top();q.pop();
		if(tmp.x == ex && tmp.y == ey) 
			return tmp.step;//箱子到达终点位置
		for(int i=0;i<4;i++) {
			int tx = tmp.x + next[i][0];
			int ty = tmp.y + next[i][1];
			int man_x = tmp.x - next[i][0];//工人目的点
			int man_y = tmp.y - next[i][1];
			if(tx<1||tx>m||ty<1||ty>n) continue;//越界
			if(map[tx][ty]==-1||vis[tx][ty]>2) continue;//重点！！！
			if(map[man_x][man_y]==-1) continue;//搬运工目的地为墙
			memset(book,0,sizeof(book));//book用来标记搬运工走过的格子
			book[tmp.x][tmp.y]=1;//标记箱子的位置
			if(bfs_move(man_x,man_y,tmp.wx,tmp.wy)) continue;//判断是否可以到达
			book[tmp.x][tmp.y]=0;//还原 
			q.push(box_move{tx,ty,man_x,man_y,tmp.step+1});
			vis[tx][ty]++;
		}
	}
	return -1;
}
int main() {
	int T;
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--) {
		cin>>m>>n;//m行n列
		int tmp,sx,sy,wx,wy;
		memset(vis,0,sizeof(vis));//vis用来标记箱子走过的格子
		for(int i=1;i<=m;i++) {
			for(int j=1;j<=n;j++) {
				cin>>tmp;
				map[i][j]=0;
				if(tmp==1) map[i][j]=-1;
				else if(tmp==2) sx=i,sy=j;//箱子起点位置 
				else if(tmp==3) ex=i,ey=j;//箱子终点位置 
				else if(tmp==4) wx=i,wy=j;//搬运工初始位置 
			}
		}
		cout<<bfs(sx,sy,wx,wy)<<endl;
	}
	return 0;
}
/*
4
5 5
3 0 1 0 0
1 0 1 4 0
0 0 1 0 0
1 0 2 0 0
0 0 0 0 0
5 5
0 3 0 0 0
1 0 1 4 0
0 0 1 0 0
1 0 2 0 0
0 0 0 0 0
5 5
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
1 1 2 1 1
4 0 3 0 0
7 4
0 0 0 0
0 0 1 0
0 2 0 3
1 4 1 0
1 0 1 0
1 0 1 0
1 0 0 0
答案应该是：-1 4 5 2
*/ 
