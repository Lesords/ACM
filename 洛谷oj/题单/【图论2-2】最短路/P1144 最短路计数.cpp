#include<iostream>//ac
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

//题解：直接bfs计算从1到各点的最短路并记录路径数
//如果再次遍历到该地点，且距离一致，则更新路径数
//注意：题目中给出的是无向边，无向边，无向边！！！

const int MAXN = 1e6+5;
const int MOD = 100003;
vector<int> g[MAXN];
int dis[MAXN],num[MAXN],vis[MAXN];//dis保存从顶点1到该点的距离
//num为到达当前点的路径数，vis记录当前点是否被访问过
int main() {
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= m;i++) {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);//无向边！！！
        g[y].push_back(x);
    }
    queue<int> q;
    q.push(1);//起点为1
    num[1] = 1;//起点路径数为1
    vis[1] = 1;//标记1
    while(!q.empty()) {
        int pos = q.front();
        q.pop();
        for(int i = 0;i < g[pos].size();i++) {//遍历所有指向点
            int now = g[pos][i];
            if(!vis[now]) {//如果为第一次遍历该点
                num[now] = num[pos]%MOD;
                dis[now] = dis[pos]+1;//距离为上一个+1
                vis[now] = 1;//标记
                q.push(now);//入队
            }
            else if(dis[now]==dis[pos]+1) {
                num[now] = (num[now]+num[pos])%MOD;//再次遍历，累加路径数
            }
        }
    }
    for(int i = 1;i <= n;i++) {
        cout<<num[i]<<"\n";
    }
    return 0;
}
