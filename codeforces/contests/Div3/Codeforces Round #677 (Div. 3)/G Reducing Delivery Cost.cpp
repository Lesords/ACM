#include<iostream>//ac
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<utility>
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;

//题解；计算n次dijkstra，算出每两个城市之间的最小距离
//然后遍历所有边，计算当前边为0的情况下所有路线的最小距离和

typedef pair<int,int> pii;
const int MAXN = 1e3+5;
struct node{
    int v,w;
    friend bool operator < (node a,node b) {
        return a.w > b.w;//优先权值小的
    }
};
vector<node> g[MAXN];
vector<pii> route,edge;//存储路线和边
int f[MAXN][MAXN],dis[MAXN],vis[MAXN];
int n,m,k;
void dijkstra(int s) {//计算s为起点的最短路径
    memset(dis,0x3f,sizeof(dis));//初始化为最大值
    memset(vis,0,sizeof(vis));//标记清零
    dis[s] = 0;//不要提前标记！！！
    priority_queue<node> q;
    q.push({s,0});//起点
    while(!q.empty()) {
        node tmp = q.top();q.pop();
        if(vis[tmp.v]) continue;//跳过已判断的
        vis[tmp.v] = 1;//否则，标记当前点
        for(int i = 0;i < g[tmp.v].size();i++) {//遍历所有可以到达的点
            node now = g[tmp.v][i];
            if(dis[now.v]>dis[tmp.v]+now.w) {
                dis[now.v] = dis[tmp.v]+now.w;
                q.push({now.v,dis[now.v]});
            }
        }
    }
    for(int i = 1;i <= n;i++) {
        f[s][i] = dis[i];
    }
}
int main() {
    cin>>n>>m>>k;
    for(int i = 1;i <= m;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        edge.push_back({u,v});//存边
        g[u].push_back({v,w});//建图，无向边
        g[v].push_back({u,w});
    }
    for(int i = 1;i <= n;i++) {//跑n次dijkstra
        dijkstra(i);
    }
    for(int i = 1;i <= k;i++) {//存路线
        int x,y;
        cin>>x>>y;
        route.push_back({x,y});
    }
    ll ans = INF;
    for(int i = 0;i < edge.size();i++) {
        pii ee = edge[i];
        ll num = 0;
        for(int j = 0;j < route.size();j++) {
            pii rr = route[j];
            //利用ee这条边，来取rr路线的较小值
            //要么rr.fi -> ee.fi  =>  ee.se -> rr.se
            //要么rr.se -> ee.fi  =>  ee.se -> rr.fi
            num += min(f[rr.fi][rr.se],min(f[rr.fi][ee.fi]+f[rr.se][ee.se],f[rr.fi][ee.se]+f[rr.se][ee.fi]));
        }
        ans = min(ans,num);//取较小值
    }
    cout<<ans;
	return 0;
}
