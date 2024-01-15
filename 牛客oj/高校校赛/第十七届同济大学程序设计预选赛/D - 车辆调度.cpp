#include<iostream>//wa
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;
struct dot{
	int x,y;
};
struct mov{
	int x,y,step;
};
char a[15][15];
int vis[15][15],book[15][15];
int nextt[4][2] = {1,0,-1,0,0,1,0,-1};
int w,h,k,car_size;
void bfs(int x,int y,int time) {
	queue<mov> q;
	q.push(mov{x,y,0});
	mov tmp;
	memset(book,0,sizeof(book));
	while(q.size()) {
		tmp = q.front();
		q.pop();
		if(tmp.step>time) continue;
		if(a[tmp.x][tmp.y]=='D') {
			if(vis[tmp.x][tmp.y]==time) continue;
			if(tmp.step==time) {
				vis[tmp.x][tmp.y] = time;
				continue;
			}
			else if(tmp.step < time){
				if(car_size>1) vis[tmp.x][tmp.y] = time;
				if((time-tmp.step)%2==0) vis[tmp.x][tmp.y] = time;
				continue;
			}
		}
		for(int i = 0;i < 4;i++) {
			int tx = tmp.x + nextt[i][0];
			int ty = tmp.y + nextt[i][1];
			if(tx<1||tx>h||ty<1||ty>w) continue;
			if(a[tx][ty]=='X'||a[tx][ty]=='R') continue;
			if(book[tx][ty]) continue;
			book[tx][ty]++;
			q.push(mov{tx,ty,tmp.step+1});
		}
	}
}
int main() {
	stack<dot> begin,end;
	cin>>w>>h>>k;
	for(int i = 1;i <= h;i++) {
		for(int j = 1;j <= w;j++) {
			cin>>a[i][j];
			if(a[i][j]=='R') {
				begin.push(dot{i,j});
			}
			if(a[i][j]=='D') {
				end.push(dot{i,j});
			}
		}
	}
	car_size = begin.size();
	while(begin.size()) {
		dot tmp = begin.top();
		begin.pop();
		bfs(tmp.x,tmp.y,k);
	}
	int flag = 0;
	while(end.size()) {
		dot tmp = end.top();
		end.pop();
		if(vis[tmp.x][tmp.y]==k) {
			flag = 1;break;
		}
	}
	cout<<(flag?"YES":"NO");
	return 0;
}
