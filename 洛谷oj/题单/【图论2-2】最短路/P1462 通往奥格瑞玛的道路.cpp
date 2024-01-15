#include<iostream>//ac
#include<queue>
#include<vector>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;

//题解：二分答案+dijkstra
//将所有城市的过路费从小到大排序，然后将排序后的数组作为二分的范围
//dijkstra来计算到达各个城市损失的血量，注意判断过路费是否满足条件

const int MAXN = 1e4+5;
struct node{
    int v,w;
    friend bool operator < (node a,node b) {
        return a.w > b.w;//优先权值小的
    }
};
int n,m,b;
int f[MAXN],c[MAXN],dis[MAXN],vis[MAXN];//vis记录当前城市是否判断过
//f为过路费原数组，c为过路费排序数组，dis存储到达该点损失的血量
vector<node> g[MAXN];//存图
bool judge(int tval) {
    for(int i = 1;i <= n;i++) dis[i] = INF,vis[i] = 0;//初始化
    priority_queue<node> q;
    q.push({1,0});
    dis[1] = 0;//起点损失为0
    while(!q.empty()) {
        node tmp = q.top();
        q.pop();
        if(vis[tmp.v]) continue;//跳过已标记的
        vis[tmp.v] = 1;//否则标记
        for(int i = 0;i < g[tmp.v].size();i++) {//遍历所有可指向点
            node now = g[tmp.v][i];
            if(f[now.v]>tval) continue;//跳过过路费大于tval的城市！！！
            if(dis[now.v]>dis[tmp.v]+now.w) {//可以松弛
                dis[now.v] = min(dis[now.v], dis[tmp.v]+now.w);
                q.push({now.v,dis[now.v]});//更新并入队
            }
        }
    }
    if(dis[n]>b) return false;//如果到达n城市的损失血量大于b，则不满足条件
    return true;
}
int main() {
    cin>>n>>m>>b;
    for(int i = 1;i <= n;i++) cin>>f[i],c[i] = f[i];
    for(int i = 1;i <= m;i++) {
        int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back({b,c});//无向边
        g[b].push_back({a,c});
    }
    if(!judge(INF)) {//如果在原条件下就无法到达n点，则直接输出AFK
        cout<<"AFK\n";//即损失的血量过多
        return 0;
    }
    sort(c+1,c+n+1);//过路费从小到大排序
    int l = 1,r = n,ans = 0;//以过路费为二分范围
    while(l<=r) {
        int mid = (l+r)>>1;
        if(judge(c[mid])) {//判断c[mid]的过路费是否满足条件
            ans = c[mid];//满足则更新结果
            r = mid-1;
        }
        else l = mid+1;
    }
    cout<<ans;
    return 0;
}
