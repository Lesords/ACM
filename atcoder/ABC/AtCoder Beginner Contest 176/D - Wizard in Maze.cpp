#include<iostream>//ac
#include<deque>
#include<algorithm>
using namespace std;

//题解：01-bfs
//根据题意可知，直接上下移动不需要花费，即权值为0
//跳到 5*5 范围里的点需要花费，即权值为1
//注意：跳的时候对应的是当前点，不是下一个位置点！！！

const int MAXN = 1e3+5;
struct node{
    int x,y,num;//(x,y)为坐标，num为花费次数
};
char a[MAXN][MAXN];
bool vis[MAXN][MAXN];//记录对应坐标是否访问过
int nextt[4][2] = {0,1,0,-1,1,0,-1,0};
int main() {
    int h,w,sx,sy,ex,ey;
    cin>>h>>w>>sx>>sy>>ex>>ey;
    for(int i = 1;i <= h;i++) {
        cin>>a[i]+1;
    }
    deque<node> q;
    q.push_back({sx,sy,0});//起点
    while(!q.empty()) {
        node tmp = q.front();
        q.pop_front();
        if(tmp.x==ex&&tmp.y==ey) {//到达终点，直接返回结果，并结束程序
            cout<<tmp.num<<"\n";
            return 0;
        }
        if(vis[tmp.x][tmp.y]) continue;//已访问，跳过
        vis[tmp.x][tmp.y] = 1;//标记当前点
        //先计算权值为0的情况
        for(int i = 0;i < 4;i++) {
            int tx = tmp.x+nextt[i][0];
            int ty = tmp.y+nextt[i][1];
            if(tx<1||tx>h||ty<1||ty>w) continue;//越界跳过
            if(vis[tx][ty]) continue;//已访问，跳过
            if(a[tx][ty]=='#') continue;//为墙，跳过
            q.push_front({tx,ty,tmp.num});//放在队首
        }
        //再计算权值为1的情况
        for(int j = -2;j <= 2;j++) {
            for(int k = -2;k <= 2;k++) {
                int nx = tmp.x+j;//以当前点为中心的 5*5 范围
                int ny = tmp.y+k;
                if(nx<1||nx>h||ny<1||ny>w) continue;//越界，跳过
                if(vis[nx][ny]||a[nx][ny]=='#') continue;//已访问或为墙，跳过
                q.push_back({nx,ny,tmp.num+1});//放在队尾
            }
        }
    }
    cout<<"-1";//没到达终点，输出-1
    return 0;
}
