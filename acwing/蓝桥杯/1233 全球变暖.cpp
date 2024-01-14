#include<iostream>//ac
#include<cstring>
using namespace std;
const int MAXN = 1e3+5;
char s[MAXN][MAXN];
int nextt[4][2] = {0,1,0,-1,1,0,-1,0};
int vis[MAXN][MAXN],mark[MAXN][MAXN],n,numa,numb;
void dfs(int x,int y) {//dfs寻找连通块
	for(int i = 0;i < 4;i++) {
		int tx = x + nextt[i][0];
		int ty = y + nextt[i][1];
		if(tx<1||tx>n||ty<1||ty>n) continue;
		if(mark[tx][ty]||s[tx][ty]=='.') continue;
		mark[tx][ty] = 1;
		dfs(tx,ty);
	}
}
int main() {
	cin>>n;
	for(int i = 1;i <= n;i++) cin>>s[i]+1;
	for(int i = 1;i <= n;i++) {//计算还没上升时的岛屿数量
		for(int j = 1;j <= n;j++) {
			if(mark[i][j]||s[i][j]=='.') continue;
			mark[i][j] = 1;
			dfs(i,j);
			numa++;
		}
	}
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) {
			if(s[i][j]=='.') continue;
			for(int k = 0;k < 4;k++) {
				int tx = i + nextt[k][0];
				int ty = j + nextt[k][1];
				if(tx<1||tx>n||ty<1||ty>n) continue;
				if(s[tx][ty]=='.') {
					vis[i][j] = 1;
					break;
				}
			}
		}
	}
	memset(mark,0,sizeof(mark));//
	for(int i = 1;i <= n;i++) {//计算上升后的岛屿数量
		for(int j = 1;j <= n;j++) {
			if(vis[i][j]||mark[i][j]||s[i][j]=='.') continue;
			mark[i][j] = 1;
			dfs(i,j);
			numb++;
		}
	}
	cout<<numa-numb<<endl;
	return 0;
}
