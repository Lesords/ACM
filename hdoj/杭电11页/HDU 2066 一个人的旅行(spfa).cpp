#include<iostream>//ac
#include<vector>
#include<queue>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;
const int MAXN = 1e3+5;

//题解：建图，跑s次spfa并更新ans数组，最后计算最小值即可

struct node{
    int dot,val;//指向点和边权值
};
vector<node> g[MAXN];//存图
int dis[MAXN],ans[MAXN],maxx,minn;
//dis记录当前spfa的结果，ans保存综合最小值，maxx为最大的点，minn为最后结果
bool vis[MAXN];//vis记录当前点是否在队列中，false为在

void spfa(int dot) {//dot为源点
    for(int i = 1;i <= maxx;i++) {//初始化
        vis[i] = true;//true为不在队列
        dis[i] = INF;//初始化为INF
    }
    dis[dot] = 0;//源点为到源点为0
    vis[dot] = false;//源点标记
    queue<int> q;
    q.push(dot);//源点入队
    while(!q.empty()) {
        int tmp = q.front();q.pop();
        vis[tmp] = true;//出队需要删除标记
        for(int i = 0;i < g[tmp].size();i++) {//遍历所有可到达点
            node now = g[tmp][i];
            if(dis[tmp]+now.val<dis[now.dot]) {//路途变短
                dis[now.dot] = dis[tmp]+now.val;//修改到达now.dot的值
                if(vis[now.dot]) {//未在队列中的，需入列
                    q.push(now.dot);
                    vis[now.dot] = false;//标记入队
                }
            }
        }
    }
}

int main() {
    int t,s,d;
    while(cin>>t>>s>>d) {//多组输入！！！
        maxx = 0,minn = INF;
        for(int i = 1;i <= t;i++) {
            int a,b,time;
            cin>>a>>b>>time;
            maxx = max(maxx,max(a,b));//记录最大点
            g[a].push_back(node{b,time});//存边
            g[b].push_back(node{a,time});
        }
        for(int i = 1;i <= maxx;i++) ans[i] = INF;//初始化为INF
        for(int i = 1;i <= s;i++) {
            int dot;cin>>dot;
            if(dot>maxx) continue;
            spfa(dot);
            for(int j = 1;j <= maxx;j++) ans[j] = min(ans[j],dis[j]);//更新较小值
        }
        for(int i = 1;i <= d;i++) {
            int dot;cin>>dot;
            if(dot>maxx) continue;
            minn = min(minn,ans[dot]);//结果取最小值
        }
        for(int i = 1;i <= maxx;i++) g[i].clear();//多组输入，记得初始化！！！
        cout<<minn<<"\n";//回车！！！
    }
    return 0;
}
