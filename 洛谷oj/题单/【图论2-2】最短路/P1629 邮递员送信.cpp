#include<iostream>//ac
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;

//题解：从起点到各个点的距离和，为单源最短路径问题，直接dijkstra即可
//但是由于边为单向的，所以返回的路径是多源单终点的最短路径问题
//所以可以反向建边，那么就可以将多源单终点问题转换为单源最短路径问题了
//由于简便写法，我们可以直接将点的编号都+n，反向建立在原图上

const int MAXN = 2e3+10;
struct node{
    int v,w;
    friend bool operator < (node a,node b) {
        return a.w > b.w;//优先边权小的
    }
};
int n,m;
int dis[MAXN],vis[MAXN];//dis记录距离，vis判断当前点是否松弛过
vector<node> g[MAXN];//保存边
void dijkstra(int s,int pls) {//s为起点，pls为增加的距离（反向建边+n
    for(int i = 1;i <= n;i++) dis[i+pls] = INF;//记录距离都需要+pls
    priority_queue<node> q;
    q.push({s+pls,0});//起点为s+pls，距离为0
    dis[s+pls] = 0;//s+pls距离为0
    while(!q.empty()) {
        node pos = q.top();
        q.pop();
        if(vis[pos.v]) continue;//跳过已松弛点
        vis[pos.v] = 1;//否则标记
        for(int i = 0;i < g[pos.v].size();i++) {//遍历所有可以指向的边
            node now = g[pos.v][i];
            if(dis[now.v]>dis[pos.v]+now.w) {//可以松弛
                dis[now.v] = dis[pos.v] + now.w;//更新权值
                q.push({now.v,dis[now.v]});//指向点入队
            }
        }
    }
}
int main() {
    cin>>n>>m;
    for(int i = 1;i <= m;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});//正边
        g[v+n].push_back({u+n,w});//反向建边，编号+n
    }
    ll ans = 0;
    dijkstra(1,0);//正边
    dijkstra(1,n);//反向边
    for(int i = 1;i <= n*2;i++) ans += dis[i];//前n为正向，后n为反向
    cout<<ans;
    return 0;
}
