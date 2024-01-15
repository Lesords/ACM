#include<iostream>//ac
#include<set>
using namespace std;
char map[105][105];
char op[10] = {'y','i','z','h','o','n','g'};//保存对应的字符
int book[105][105],n;
//八个方向
int nextt[8][2] = {0,1,1,1,1,0,1,-1,0,-1,-1,-1,-1,0,0,-1};
struct node{
	int x,y;
}trace[10];//保存路径坐标
void dfs(int x,int y,int dir,int step) {
	//step（表下一步）从2开始，所以对应的需 -1
	trace[step-1].x = x,trace[step-1].y = y;//保存路径坐标
	if(step==8) {//满足条件时
		for(int i = 1;i <= 7;i++) {
			book[trace[i].x][trace[i].y] = 1;
		}//路径上的坐标都标记为1
		return ;
	}
	int tx = x + nextt[dir][0];
	int ty = y + nextt[dir][1];
	if(tx<0||tx>=n||ty<0||ty>=n) return;//越界
	//op数组从0开始，所以step需 -1
	if(map[tx][ty]!=op[step-1]) return;//与对应字符不一样
	dfs(tx,ty,dir,step+1);
}
int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 0;i < n;i++) cin>>map[i];
	for(int i = 0;i < n;i++) {
		for(int j = 0;j < n;j++) {
			if(book[i][j]) continue;//已标记过
			if(map[i][j]=='y') {//y开头才遍历
				for(int k = 0;k <= 7;k++) dfs(i,j,k,2);//第2位
			}//遍历8个方向
		}
	}
	for(int i = 0;i < n;i++) {
		for(int j = 0;j < n;j++) {//没有标记的为 *
			cout<<(book[i][j]?map[i][j]:'*');
		}
		cout<<endl;
	}
	return 0;
}
