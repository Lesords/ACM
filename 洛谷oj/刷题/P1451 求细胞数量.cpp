#include<iostream>//ac
#include<algorithm>
using namespace std;

//题解：dfs求联通块

int n,m,vis[105][105],ans;
int nextt[4][2] = {0,1,1,0,0,-1,-1,0};//四个方向
char a[105][105];
void dfs(int x,int y) {
    vis[x][y] = 1;//起点
    for(int i = 0;i < 4;i++) {
        int tx = x + nextt[i][0];
        int ty = y + nextt[i][1];
        if(tx<1||tx>n||ty<1||ty>m) continue;//越界
        if(a[tx][ty]=='0'||vis[tx][ty]) continue;//非细胞或已访问
        vis[tx][ty] = 1;//标记当前点
        dfs(tx,ty);//继续dfs
    }
}
int main() {
    cin>>n>>m;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) cin>>a[i][j];
    }
    for(int i = 1;i <= n;i++) {//所有点进行dfs
        for(int j = 1;j <= m;j++) {
            //不为细胞或已访问
            if(a[i][j]=='0'||vis[i][j]) continue;
            dfs(i,j);ans++;//还未访问的细胞
        }
    }
    cout<<ans<<endl;
    return 0;
}
