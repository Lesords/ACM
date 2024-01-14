#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
int m,n,k,lim,vis[51][51][51],map[51][51][51],ans;
struct node {
	int x,y,z,step;
};
bool bfs() {
	queue<node> q;
	q.push({1,1,1,0});//可以不加node名字
	int next[6][3]={{1,0,0},{0,1,0},{-1,0,0},{0,-1,0},
	{0,0,-1},{0,0,1}};//6个方向 
	while(!q.empty()) {
		node tmp=q.front();
		q.pop();
		if(tmp.x==n&&tmp.y==m&&tmp.z==k) {
			ans=tmp.step;
			if(ans<=lim) return true;//很关键，审题 
			return false;
		}
		for(int i=0;i<6;i++) {
			int tx=tmp.x+next[i][0];//三个方向
			int ty=tmp.y+next[i][1];
			int tz=tmp.z+next[i][2];
			if(tx<1||tx>n||ty<1||ty>m||tz<1||tz>k) continue;//越界
			if(map[tz][tx][ty]||vis[tz][tx][ty]) continue;//墙和已走过
			q.push({tx,ty,tz,tmp.step+1});
			vis[tz][tx][ty]=1;//很关键 ，注意下标顺序
		}
	}
	return false;//默认返回值不确定
}
int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		scanf("%d%d%d%d",&k,&n,&m,&lim);//k块，n行，m列 
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=k;i++)
			for(int j=1;j<=n;j++)
				for(int u=1;u<=m;u++) 
					scanf("%d",&map[i][j][u]);
		if(bfs()) cout<<ans<<endl;
		else cout<<"-1"<<endl;
	}
	return 0;
}
