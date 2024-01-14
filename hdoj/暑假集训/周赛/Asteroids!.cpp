#include<iostream>
#include<cstring>
#include<string>
#include<queue>
using namespace std;
struct node {
	int x,y,z,step;
};
int sx,sy,sz,ex,ey,ez,n,map[15][15][15],vis[15][15][15],ans;
bool bfs() {
	queue<node> q;
	q.push(node{sx,sy,sz,0}); 
	int next[6][3]={{0,1,0},{0,-1,0},{1,0,0},{-1,0,0}, 
	{0,0,1},{0,0,-1}};//6个方向 
	node tmp;
	while(!q.empty()) {
		tmp=q.front();
		q.pop();
		if(tmp.x==ex&&tmp.y==ey&&tmp.z==ez) {
			ans=tmp.step;
			return true;
		}
		for(int i=0;i<6;i++) {
			int tx=tmp.x+next[i][0];
			int ty=tmp.y+next[i][1];
			int tz=tmp.z+next[i][2];
			if(tx<0||tx>=n||ty<0||ty>=n||tz<0||tz>=n) continue;
			if(vis[tz][tx][ty]||map[tz][tx][ty]) continue;
			q.push(node{tx,ty,tz,tmp.step+1});
			vis[tz][tx][ty]=1;//tz,tx,ty顺序很关键 
		}
	}
	return false;
}
int main() {
	string op;
	char ch;
	while(cin>>op>>n) {//op 用来过滤 START 
		for(int k=0;k<n;k++)
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++) {
					cin>>ch;
					map[k][i][j]=ch=='X'?1:0;
				}
		cin>>sx>>sy>>sz>>ex>>ey>>ez;
		cin>>op;//过滤 END
		memset(vis,0,sizeof(vis));
		if(bfs()) cout<<n<<' '<<ans<<endl;
		else cout<<"NO ROUTE"<<endl;
	}
	return 0;
} 
