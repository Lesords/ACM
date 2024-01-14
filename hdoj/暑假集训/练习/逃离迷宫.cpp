#include<iostream>
#include<cstring>
using namespace std;
int a[105][105],vis[105][105],flag;
int n,m,ex,ey,sx,sy,k;
void dfs(int x,int y,int dir){
    if(x==ex&&y==ey) {
        if(vis[x][y]<=k) flag=1;//满足条件 
        return;
    }
    if(vis[x][y]>k) return ;
    if(vis[x][y]==k&&x!=ex&&y!=ey) return ;
    int next[4][2]={
        {1,0},{0,1},{-1,0},{0,-1}
    };
    for(int i=0;i<4;i++) {
        int tx=x+next[i][0];
        int ty=y+next[i][1];
        if(tx<1||tx>m||ty<1||ty>n) continue;//overborder
        if(a[tx][ty]||vis[tx][ty]<vis[x][y]) continue;
        //vis[tx][ty]<vis[x][y] is important
        if(dir!=-1&&dir!=i&&vis[tx][ty]<vis[x][y]+1) continue;
        vis[tx][ty]=vis[x][y];
        if(dir!=-1&&i!=dir) vis[tx][ty]++;//方向不同 
        dfs(tx,ty,i);
        if(flag) return;
    }
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        flag=0;
        cin>>m>>n;// >>m>>n  not >>n>>m
        for(int i=1;i<=m;i++) {
            for(int j=1;j<=n;j++) {
                char ch;
                cin>>ch;
                if(ch=='.') a[i][j]=0;
                else a[i][j]=1;
                vis[i][j]=99999;
            }
        }
        cin>>k>>sy>>sx>>ey>>ex;
        vis[sx][sy]=0;//初始方向数为0 
        dfs(sx,sy,-1);
        if(flag) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
}
