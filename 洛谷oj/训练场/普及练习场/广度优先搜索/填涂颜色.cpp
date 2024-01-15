#include<iostream>//ac
#include<queue> 
using namespace std;
struct node{
	int x,y;
};
int n,map[35][35],vis[35][35];
int nextt[4][2] = {0,1,1,0,0,-1,-1,0};
int bfs(int x,int y) {
	int flag = 1;//1为闭合圈，0为非闭合
	queue<node> q;
	q.push(node{x,y});
	node tmp;
	while(!q.empty()) {
		tmp = q.front();q.pop();
		for(int i = 0;i < 4;i++) {
			int tx = tmp.x + nextt[i][0];
			int ty = tmp.y + nextt[i][1];
			if(tx<1||tx>n||ty<1||ty>n) {//越界
				flag = 0;continue;//说明不是闭合圈
			}//不是闭合圈也要标记，避免重复判断！！！
			if(map[tx][ty]||vis[tx][ty]) continue;
			vis[tx][ty] = 1;//标记已遍历过的
			q.push(node{tx,ty});
		}
	}
	return flag;
}
void change(int x,int y) {//dfs
	map[x][y] = 2;//赋值为2
	for(int i = 0;i < 4;i++) {
		int tx = x + nextt[i][0];
		int ty = y + nextt[i][1];
		if(map[tx][ty]) continue;//跳过闭合圈和已赋值的
		change(tx,ty);//递归
	}
}
int main() {
	int flag = 0;
	cin>>n; 
	for(int i = 1;i <= n;i++) 
		for(int j = 1;j <= n;j++) cin>>map[i][j];
	for(int i = 1;i <= n && !flag;i++) {
		for(int j = 1;j <= n;j++) {
			//跳过 已判断过 和 闭合圈（即1）
			if(map[i][j]||vis[i][j]) continue;
			if(bfs(i,j)) {//判断是闭合圈
				change(i,j);//若是，则将闭合圈的数字改为2
				flag = 1;break;//退出循环
			}
		}
	}
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) {
			if(j!=1) cout<<' ';
			cout<<map[i][j];
		}
		cout<<endl;
	}
	return 0;
}
