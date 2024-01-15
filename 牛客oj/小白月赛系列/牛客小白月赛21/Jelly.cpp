#include<iostream>//ac
#include<queue> 
using namespace std;
char map[105][105][105];
int book[105][105][105],n,ans = 0;
struct jam{
	int x,y,z,step;//step为果冻数量
	friend bool operator < (jam a,jam b) {
		return a.step>b.step;
	}
};
int bfs(int x,int y, int z) {
	int next[6][3] = {0,0,-1,0,0,1,1,0,0,0,1,0,-1,0,0,0,-1,0};
	priority_queue<jam> q;
	q.push({x,y,z,1});//起始位置绝对有果冻
	while(!q.empty()) {
		jam tmp = q.top();
		q.pop();
		if(tmp.x==n&tmp.y==n&&tmp.z==n) {
			ans = tmp.step;
			return 1;
		}
		for(int i = 0;i < 6;i++) {
			int tx = tmp.x+next[i][0];
			int ty = tmp.y+next[i][1];
			int tz = tmp.z+next[i][2];
			if(tx<1||tx>n||ty<1||ty>n||tz<1||tz>n) continue;
			if(book[tx][ty][tz]||map[tz][tx][ty]=='*') continue;
			book[tx][ty][tz] = 1;//标记已经走过的
			q.push({tx,ty,tz,tmp.step+1});
		}
		
	}
	return 0;
}
int main() {
	cin>>n;
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) {
			for(int k = 1;k <= n;k++) {
				cin>>map[i][j][k];
			}
		}
	}
	if(bfs(1,1,1)) cout<<ans<<endl;
	else cout<<"-1"<<endl;
	return 0;
}
