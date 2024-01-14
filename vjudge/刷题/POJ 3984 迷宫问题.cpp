#include<iostream>//ac  (G++ ac)
#include<cstdio>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;
struct node{
	int x,y,step;
};
int a[6][6],vis[6][6],cnt;
int nextt[4][2] = {1,0,0,1,-1,0,0,-1};
void bfs(int x,int y) {//寻找最短路径到右下角，并标记走过位置
	queue<node> q;
	q.push(node{x,y,0});//C++不支持该写法
	node tmp;
	while(!q.empty()) {
		tmp = q.front();
		q.pop();
		if(tmp.x==4&&tmp.y==4) {
			cnt = tmp.step;break;//cnt为最短步数
		}
		for(int i = 0;i < 4;i++) {
			int tx = tmp.x + nextt[i][0];
			int ty = tmp.y + nextt[i][1];
			if(tx<0||tx>4||ty<0||ty>4) continue;//边界
			if(!tx&!ty||vis[tx][ty]||a[tx][ty]) continue;
			//起始点，墙，已走过
			vis[tx][ty] = tmp.step+1;//标记当前位置所需步数
			q.push(node{tx,ty,tmp.step+1});
		}
	}
}
void solve(int x,int y,int step) {//从终点到起点反向寻找
	stack<node> ans;//栈后进先出，满足寻找路径
	ans.push(node{x,y,step});//添加终点
	while(step) {//寻找step-1所在的位置，即(x,y)前一个位置
		for(int i = 0;i < 4;i++) {
			int tx = x + nextt[i][0];
			int ty = y + nextt[i][1];
			if(tx<0||tx>4||ty<0||ty>4) continue;//边界
			if(a[tx][ty]) continue;//墙
			//如果当前位置为前一步时，vis[tx][ty] = step-1
			if(vis[tx][ty]!=step-1) continue;//不满足情况
			x = tx,y = ty;//更新当前位置
			ans.push(node{tx,ty,--step});//入栈并修改step
		}
	}
	node tmp;
	while(ans.size()) {//将栈内数据全部输出即可
		tmp = ans.top(),ans.pop();
		printf("(%d, %d)\n",tmp.x,tmp.y);
	}
}
int main() {
	for(int i = 0;i < 5;i++)
		for(int j = 0;j < 5;j++)
			scanf("%d",&a[i][j]);
	bfs(0,0);//寻找最短路径
	solve(4,4,cnt);//方向寻找，输出路径
	return 0;
}
