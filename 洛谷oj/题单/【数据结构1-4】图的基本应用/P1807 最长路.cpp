#include<iostream>//ac
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

//题解：拓扑排序从1开始更新维护到达各点的最远距离
//需要注意：有的点1无法到达，但是入度也为0，所以需先处理对应的指向点的入度--

const int MAXN = 1510;
struct node{
    int dot,val;//dot存储指向点，val存储边权
};
vector<node> g[MAXN];//存图
int in[MAXN],to[MAXN];//in存入度，to存从1到达某点的最远距离
int main() {
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= m;i++) {//m个边
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back(node{v,w});//存储边
        in[v]++;//入度
    }
    for(int i = 2;i <= n;i++) {//处理除起点外其他点入度为0的情况
        if(in[i]) continue;
        for(int j = 0;j < g[i].size();j++) in[g[i][j].dot]--;//指向点入度--
    }
    queue<int> q;
    q.push(1);//从1开始
    while(!q.empty()) {//拓扑排序
        int tmp = q.front();q.pop();
        for(int i = 0;i < g[tmp].size();i++) {//遍历所有指向点
            node tt = g[tmp][i];
            to[tt.dot] = max(to[tt.dot],to[tmp]+tt.val);//更新最远距离
            if(--in[tt.dot]==0) {//若入度为0则入队列
                q.push(tt.dot);
            }
        }
    }
    if(to[n]==0) cout<<"-1\n";//为0表示不联通
    else cout<<to[n]<<endl;
    return 0;
}
