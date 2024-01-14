#include<iostream>//ac
#include<queue>
#include<vector>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;
const int MAXN = 505;
struct node{
    int dot,val;//dot为指向点，val为对应边的长度
    friend bool operator < (node a,node b) {
        return a.val > b.val;
    }
};
vector<node> g[MAXN];//g存图
int n,m,s,d,num[MAXN],pa[MAXN],cnt[MAXN],sum[MAXN],dis[MAXN],vis[MAXN];
//num保存对应城市的队伍数量，pa保存对应城市的上一个位置
//cnt保存到达对应城市的路径数，sum为到达对应城市可以有的队伍总数
//dis表示到达对应位置的长度，vis保存当前城市是否松弛过
void dijkstra(int s) {
    for(int i = 0;i < n;i++) dis[i] = INF;//初始化为无限大
    dis[s] = 0;//源点的路径为0
    cnt[s] = 1;//源点的路径数为1
    sum[s] = num[s];//源点的队伍总数为本身队伍数
    priority_queue<node> q;
    q.push(node{s,0});//源点入队
    while(!q.empty()) {
        node tmp = q.top();q.pop();
        if(vis[tmp.dot]) continue;//已松弛的跳过
        else vis[tmp.dot] = 1;//其他的赋值为1
        for(int i = 0;i < g[tmp.dot].size();i++) {
            node now = g[tmp.dot][i];
            if(dis[now.dot]>dis[tmp.dot]+now.val) {//可松弛
                dis[now.dot] = dis[tmp.dot]+now.val;//更新长度
                pa[now.dot] = tmp.dot;//修改上一个位置城市
                cnt[now.dot] = cnt[tmp.dot];//路径数即为上一个城市的路径数
                sum[now.dot] = num[now.dot] + sum[tmp.dot];//队伍数为 当前+上一个城市总数
                if(!vis[now.dot]) q.push(node{now.dot,dis[now.dot]});//未松弛的入队
                //不可再次标记，还未松弛！！！
            }
            else if(dis[now.dot]==dis[tmp.dot]+now.val) {//若相等，表示有多个路径
                cnt[now.dot] += cnt[tmp.dot];//累加路径数
                if(num[now.dot]+sum[tmp.dot]>sum[now.dot]) {//若队伍数较多，则更新
                    pa[now.dot] = tmp.dot;//更新上一个位置的城市
                    sum[now.dot] = num[now.dot] + sum[tmp.dot];//修改队伍数
                }
            }
        }
    }
}
void out_path(int dot) {//递归输出路径
    if(dot==s) {//到达起点直接输出
        cout<<s;
        return ;
    }
    out_path(pa[dot]);//先递归后输出（可从头到尾输出）
    cout<<" "<<dot;
}
int main() {
    cin>>n>>m>>s>>d;
    for(int i = 0;i < n;i++) cin>>num[i];
    for(int i = 1;i <= m;i++) {
        int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back(node{b,c});//存图
        g[b].push_back(node{a,c});
    }
    dijkstra(s);
    cout<<cnt[d]<<" "<<sum[d]<<"\n";
    out_path(d);
    return 0;
}
