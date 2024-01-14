#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int ex,ey,sx,sy,ans,map[9][9],vis[9][9];//1-8
struct node{
	int x,y,step;
};
void bfs() {
	queue<node> q;
	q.push(node{sx,sy,0});
	node tmp;
	int next[8][2]={1,2,1,-2,2,1,2,-1,
	-1,2,-1,-2,-2,-1,-2,1};//°Ë¸ö²½×Ó 
	while(!q.empty()) {
		tmp=q.front();
		q.pop();
		if(tmp.x==ex&&tmp.y==ey) {
			ans=tmp.step;
			return ;
		}
		for(int i=0;i<8;i++) {
			int tx=tmp.x+next[i][0];
			int ty=tmp.y+next[i][1];
			if(tx<1||tx>8||ty<1||ty>8||vis[tx][ty]) continue;
			vis[tx][ty]=1;
			q.push(node{tx,ty,tmp.step+1});
		}
	}
}
int main() {
	string s,e;
	while(cin>>s>>e) {
		sx=s[0]-'a'+1,sy=s[1]-'0';
		ex=e[0]-'a'+1,ey=e[1]-'0';
		memset(vis,0,sizeof(vis));
		bfs();
		//cout<<sx<<sy<<ex<<ey<<endl;
		cout<<"To get from "<<s<<" to "<<e;
		cout<<" takes "<<ans<<" knight moves."<<endl;
	}
	return 0;
} 
