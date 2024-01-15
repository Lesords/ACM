#include<iostream>//ac
#include<queue>
#include<algorithm>
using namespace std;
struct node{
    int x,y,step;
};
int tim[305][305],vis[305][305],bomb[305][305];
//tim记录流星到达该点的时间，vis为是否走过，bomb为当前点是否有流星
int nextt[4][2] = {0,1,1,0,0,-1,-1,0};//四个方向
void update(int x,int y,int t) {
    //如果已有炸弹，更新最小值，否则直接赋值
    if(tim[x][y]) tim[x][y] = min(tim[x][y],t);
    else tim[x][y] = t;
    bomb[x][y] = 1;//当前位置有炸弹
    for(int i = 0;i < 4;i++) {
        int tx = x + nextt[i][0];
        int ty = y + nextt[i][1];
        if(tx<0||ty<0) continue;//越界
        //如果已有炸弹，更新最小值，否则直接赋值
        if(tim[tx][ty]) tim[tx][ty] = min(tim[tx][ty],t);
        else tim[tx][ty] = t;
        bomb[tx][ty] = 1;//当前位置有炸弹
    }
}
int bfs(int x,int y,int step) {
    queue<node> q;
    vis[0][0] = 1;//标记为已走过
    q.push(node{x,y,step});//起点
    while(!q.empty()) {
        node tmp = q.front();q.pop();
        //如果当前点没有炸弹返回答案
        if(!bomb[tmp.x][tmp.y]) return tmp.step;
        for(int i = 0;i < 4;i++) {
            int tx = tmp.x + nextt[i][0];
            int ty = tmp.y + nextt[i][1];
            if(tx<0||ty<0||vis[tx][ty]) continue;//越界和已访问
            //当前位置有流星并且在贝茜到达之前砸到该点
            if(bomb[tx][ty]&&tim[tx][ty]<=tmp.step+1) continue;
            vis[tx][ty] = 1;//标记当前点
            q.push(node{tx,ty,tmp.step+1});
        }
    }
    return -1;//无解返回-1
}
int main() {
    int m;
    cin>>m;
    for(int i = 1;i <= m;i++) {
        int x,y,t;
        cin>>x>>y>>t;
        update(x,y,t);//更新对应位置的炸弹信息
    }
    cout<<bfs(0,0,0)<<endl;//起点为(0,0)，时间为0
    return 0;
}
