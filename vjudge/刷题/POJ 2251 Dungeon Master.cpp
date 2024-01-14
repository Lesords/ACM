#include<iostream>//ac
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
struct person{
	int x,y,z,step;
};
char map[35][35][35];
int book[35][35][35];
int sx,sy,sz,ex,ey,ez,ans,a,b,c;
bool bfs() {
	queue<person> q;
	q.push({sx,sy,sz,0});
	int next[6][3] = {1,0,0,0,-1,0,-1,0,0,0,1,0,
	0,0,1,0,0,-1};
	memset(book,0,sizeof(book));//初始化！
	while(!q.empty()) {
		person tmp = q.front();
		q.pop();
		if(tmp.x == ex&&tmp.y == ey&&tmp.z == ez) {
			ans = tmp.step;
			return 1;
		}
		for(int i = 0;i < 6;i++) {
			int tx = tmp.x + next[i][0];
			int ty = tmp.y + next[i][1];
			int tz = tmp.z + next[i][2];
			if(tx<1||tx>c||ty<1||ty>b||tz<1||tz>a) continue;
			//边界问题（1~a、b、c）
			if(map[tz][ty][tx] == '#') continue;
			if(book[tz][ty][tx]) continue;
			q.push({tx,ty,tz,tmp.step+1});
			book[tz][ty][tx] = 1;
		}
	}
	return 0;
}
int main() {
	while(cin>>a>>b>>c&&a+b+c) {
		memset(map,0,sizeof(map));
		ans = 0;
		for(int i = 1;i <= a;i++) {
			for(int j = 1;j <= b;j++) {
				for(int k = 1;k <= c;k++) {
					cin>>map[i][j][k];
					if(map[i][j][k]=='S') sx = k,sy = j,sz = i;
					if(map[i][j][k]=='E') ex = k,ey = j,ez = i;
				}
			}
			getchar();//处理回车字符
		}
		if(bfs()) cout<<"Escaped in "<<ans<<" minute(s)."<<endl;
		else cout<<"Trapped!"<<endl;
	}
	return 0;
}
