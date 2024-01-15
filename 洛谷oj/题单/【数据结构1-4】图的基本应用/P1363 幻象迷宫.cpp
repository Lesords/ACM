#include<iostream>//ac
#include<cstring>
#include<algorithm>
using namespace std;

//题解：将迷宫向周围扩散，不断拼接起来，那么对于无限远的情况可以为
//重复访问一个点（对应原迷宫），并且两次访问的实际坐标不一样
//可以重复访问一个点，说明可以无限循环这个路径，直至无限远
//所以直接从起点开始dfs，利用vis来记录当前点是否走过以及走过的点的实际坐标

const int MAXN = 1505;
char s[MAXN][MAXN];
int nextt[4][2] = {0,1,0,-1,1,0,-1,0};                      //四个方向
int n,m,flag,vis[MAXN][MAXN][3];                            //flag记录是否可以到达无限远
//vis[x][y][0]为点(x,y)是否遍历过
//vis[x][y][1]为访问点(x,y)的实际坐标x
//vis[x][y][2]为访问点(x,y)的实际坐标y
void dfs(int x,int y,int lx,int ly) {//(x,y)为在原迷宫上的对应坐标，(lx,ly)为实际坐标
    if(flag) return;                                        //确定结果，直接返回
    //当前实际坐标跟上一次访问时的实际坐标对比，而不是当前坐标和实际坐标对比！！！
    //当前位置已访问过，且有一个坐标值与上一个不相同
    if(vis[x][y][0]&&(vis[x][y][1]!=lx||vis[x][y][2]!=ly)) {
        flag = 1;return;
    }
    vis[x][y][0] = 1;                                       //标记当前点
    vis[x][y][1] = lx,vis[x][y][2] = ly;                    //记录实际坐标
    for(int i = 0;i < 4;i++) {
        int tx = (x+nextt[i][0]+n)%n;                       //对应原迷宫的坐标，需取模
        int ty = (y+nextt[i][1]+m)%m;
        int mx = lx + nextt[i][0];                          //实际坐标
        int my = ly + nextt[i][1];
        if(s[tx][ty]=='#') continue;                        //跳过墙
        //当前点未遍历过或者遍历过的实际坐标不相同，则可以继续遍历
        if(!vis[tx][ty][0]||vis[tx][ty][1]!=mx||vis[tx][ty][2]!=my) {
            dfs(tx,ty,mx,my);
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    while(cin>>n>>m) {
        memset(vis,0,sizeof(vis));                          //初始化为0
        flag = 0;
        int sx,sy;
        for(int i = 0;i < n;i++) {                          //方便取模，则从0开始记录
            for(int j = 0;j < m;j++) {
                cin>>s[i][j];
                if(s[i][j]=='S') {                          //记录起点坐标
                    sx = i,sy = j;
                }
            }
        }
        dfs(sx,sy,sx,sy);
        if(flag) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}
