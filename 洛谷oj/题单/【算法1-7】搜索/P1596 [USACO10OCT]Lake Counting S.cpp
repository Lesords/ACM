#include<iostream>//ac
#include<algorithm>
using namespace std;

//题解：dfs求连通块

char map[105][105];
bool vis[105][105];//记录是否访问过
int nextt[8][2] = {1,0,1,1,0,1,-1,1,-1,0,-1,-1,0,-1,1,-1};//八个方向
int n,m,ans;
void dfs(int x,int y) {//(x,y)开始计算联通块
    for(int i = 0;i < 8;i++) {
        int tx = x + nextt[i][0];
        int ty = y + nextt[i][1];
        if(tx<1||tx>n||ty<1||ty>m) continue;//越界
        if(map[tx][ty]=='.'||vis[tx][ty]) continue;//空的或已访问
        vis[tx][ty] = 1;//标记
        dfs(tx,ty);//继续dfs
    }
}
int main() {
    cin>>n>>m;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++) cin>>map[i][j];
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            if(map[i][j]=='.'||vis[i][j]) continue;//空的或已访问！！！
            vis[i][j] = 1;//标记起点
            dfs(i,j);ans++;//出现一个新的块
        }
    }
    cout<<ans<<endl;//输出结果
    return 0;
}
