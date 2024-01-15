#include<iostream>//ac
#include<cstring>
#include<queue>
using namespace std;
const int MAXN = 1010;
int n,m,vis[MAXN][MAXN],ans[MAXN][MAXN];
int nextt[4][2] = {0,1,1,0,0,-1,-1,0};
char map[MAXN][MAXN];
struct node {
	int x,y;
};
int bfs(int x,int y) {
	if(ans[x][y]) return ans[x][y];//如果已计算过，直接返回结果
	queue<node> q;
	q.push(node{x,y});
	vis[x][y] = 1;//标记起始点
	int sum = 1;//至少有一个（本身）
	node tmp;
	while(!q.empty()) {
		tmp = q.front();q.pop();
		for(int i = 0;i < 4;i++) {
			int tx = tmp.x + nextt[i][0];
			int ty = tmp.y + nextt[i][1];
			if(tx<0||tx>=n||ty<0||ty>=n) continue;//越界
			if(map[tx][ty]==map[tmp.x][tmp.y]) continue;//两位相同
			if(vis[tx][ty]) continue;//已走过
			vis[tx][ty] = 1;
			sum++;
			q.push(node{tx,ty});
		}
	}
	q.push(node{x,y});//防止独立块的情况下重复计算
	vis[x][y] = 0;//起始点清零！！！
	while(!q.empty()) {//遍历所有连接块
		tmp = q.front();q.pop();
		for(int i = 0;i < 4;i++) {
			int tx = tmp.x + nextt[i][0];
			int ty = tmp.y + nextt[i][1];
			if(tx<0||tx>=n||ty<0||ty>=n) continue;
			if(!vis[tx][ty]) continue;//跳过未标记块
			ans[tx][ty] = sum;//大小都一样，为sum
			vis[tx][ty] = 0;//置零
			q.push(node{tx,ty});
		}
	}
	return ans[x][y] = sum;//保存起始点结果
}
int main() {
	int a,b;
	scanf("%d%d",&n,&m);
	for(int i = 0;i < n;i++) scanf("%s",map[i]);
	for(int i = 1;i <= m;i++) {
		scanf("%d%d",&a,&b);//起始位为0
		printf("%d\n",bfs(a-1,b-1));//减一位
	}
	return 0;
}
