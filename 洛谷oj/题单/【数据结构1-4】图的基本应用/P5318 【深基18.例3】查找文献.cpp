#include<iostream>//ac
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

//题解：vector建图，然后排序，最后直接dfs和bfs即可

const int MAXN = 1e5+5;
vector<int> g[MAXN],ansbfs,ansdfs;          //g存图
int n,m,vis[MAXN];                          //vis判断点是否遍历过
void dfs(int pos,int num) {                 //pos为当前位置，num为已经遍历的数量
    if(num==n+1) return;                    //说明n个都找到了
    for(int i = 0;i < g[pos].size();i++) {  //遍历所有指向点
        int now = g[pos][i];
        if(vis[now]) continue;              //跳过已遍历的点
        vis[now] = 1;                       //标记当前点
        ansdfs.push_back(now);              //记录dfs序
        dfs(now,num+1);                     //继续dfs
    }
}
void bfs() {
    memset(vis,0,sizeof(vis));              //初始化为0
    queue<int> q;
    q.push(1);                              //起点为1
    vis[1] = 1;                             //标记起点
    ansbfs.push_back(1);                    //记录起点
    while(!q.empty()) {
        int dot = q.front();                //取队首
        q.pop();
        for(int i = 0;i < g[dot].size();i++) {//遍历所有指向点
            int now = g[dot][i];
            if(vis[now]) continue;          //跳过已遍历的点
            vis[now] = 1;                   //标记当前点
            ansbfs.push_back(now);
            q.push(now);                    //继续入队
        }
    }
}
int main() {
    cin>>n>>m;
    for(int i = 1;i <= m;i++) {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);                  //存图
    }
    for(int i = 1;i <= n;i++) sort(g[i].begin(),g[i].end());//指向点排序
    ansdfs.push_back(1);                    //dfs起点
    vis[1] = 1;
    dfs(1,1);
    bfs();
    for(auto v:ansdfs) cout<<v<<" ";        //输出对应结果
    cout<<"\n";
    for(auto v:ansbfs) cout<<v<<" ";
    return 0;
}
