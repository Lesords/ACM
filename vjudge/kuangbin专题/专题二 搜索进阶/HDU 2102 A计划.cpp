#include<iostream>//ac
#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
struct node{
    int x,y,z,step;
    friend bool operator < (node a,node b) {
        return a.step > b.step;//优先步数少的
    }
};
char g[2][15][15];
int n,m,t,vis[2][15][15];
int sx,sy,sz,px,py,pz;//起点和终点
int nextt[4][2] = {0,1,0,-1,1,0,-1,0};//四个方向（只能横移，上下靠传送）
bool bfs(int x,int y,int z,int tim) {//判断是否能在tim时间内找到公主
    priority_queue<node> q;
    node tmp = {x,y,z,0};//初始化的点步数为0
    q.push(tmp);
    while(!q.empty()) {
        tmp = q.top();q.pop();
        if(vis[tmp.z][tmp.x][tmp.y]) continue;//判断是否已访问过
        else vis[tmp.z][tmp.x][tmp.y] = 1;
        if(tmp.x==px&&tmp.y==py&&tmp.z==pz) {//到底目的点
            return tmp.step <= tim;//直接判断是否在tim时间内
        }
        if(tmp.step>tim) return false;//超时，则肯定无解
        for(int i = 0;i < 4;i++) {//只能四个方向横移
            int tx = tmp.x+nextt[i][0];
            int ty = tmp.y+nextt[i][1];
            int tz = tmp.z;
            //越界了！！！不能包括n和m！！！
            if(tx<0||tx>=n||ty<0||ty>=m) continue;//越界
            if(g[tz][tx][ty]=='#') {//若当前点为传送机
                tz ^= 1;//只有0和1两层，所以取反即可
                if(g[tz][tx][ty]=='#') continue;//若另外一个层还是传送机，则跳过
            }
            if(vis[tz][tx][ty]||g[tz][tx][ty]=='*') continue;//跳过已标记和墙
            node tt = {tx,ty,tz,tmp.step+1};
            q.push(tt);
        }
    }
    return false;
}
int main() {
    int c;
    cin>>c;
    while(c--) {
        cin>>n>>m>>t;
        getchar();
        for(int i = 0;i <= 1;i++) {
            for(int j = 0;j < n;j++) {
                cin>>g[i][j];
                for(int k = 0;k < m;k++) {//处理起点和终点
                    if(g[i][j][k]=='S') sx = j,sy = k,sz = i;
                    if(g[i][j][k]=='P') px = j,py = k,pz = i;
                }
            }
        }
        memset(vis,0,sizeof(vis));//初始化
        if(bfs(sx,sy,sz,t)) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
