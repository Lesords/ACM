#include<iostream>//ac dfs求连通块
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 105;
int n,m,vis[MAXN][MAXN];
int nextt[8][2] = {0,1,0,-1,1,0,-1,0,1,1,-1,1,1,-1,-1,-1};//8个方向
char s[MAXN][MAXN];
void dfs(int x,int y) {//标记所有与 (x,y) 联通的位置
    vis[x][y] = 1;
    for(int i = 0;i < 8;i++) {//8个方向
        int tx = x+nextt[i][0];
        int ty = y+nextt[i][1];
        if(tx<1||tx>n||ty<1||ty>m) continue;//越界
        if(vis[tx][ty]||s[tx][ty]=='*') continue;//已标记或为空
        dfs(tx,ty);
    }
}
int main() {
    while(cin>>n>>m&&n+m) {
        for(int i = 1;i <= n;i++) cin>>s[i]+1;
        memset(vis,0,sizeof(vis));
        int ans = 0;//初始化
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= m;j++) {//以所有点为起点
                if(vis[i][j]||s[i][j]=='*') continue;//跳过已标记或为空的点
                dfs(i,j);
                ans++;//统计结果
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
