#include<iostream>//ac 匈牙利算法
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN = 505;
int k,m,n;
int vis[MAXN],match[MAXN];//vis记录是否判断过，match记录匹配的对象编号
vector<int> g[MAXN];//存图
int dfs(int u) {//找增广路
    for(int i = 0;i < g[u].size();i++) {
        int now = g[u][i];
        if(vis[now]) continue;//跳过已判断的点
        vis[now] = 1;
        //未匹配 或 匹配的对象有新的对象
        if(match[now]==0||dfs(match[now])) {
            match[now] = u;//保存匹配的对象
            return 1;
        }
    }
    return 0;
}
int hungarian() {//计算匹配的数量
    int ans = 0;
    for(int i = 1;i <= m;i++) {
        for(int j = 1;j <= n;j++) vis[j] = 0;//标记清零
        if(dfs(i)) ans++;
    }
    return ans;
}
int main() {
    while(cin>>k&&k) {
        memset(match,0,sizeof(match));//初始化
        cin>>m>>n;
        for(int i = 1;i <= m;i++) g[i].clear();//初始化
        for(int i = 1;i <= k;i++) {
            int x,y;
            cin>>x>>y;
            g[x].push_back(y);//存图
        }
        //封装后，直接调用
        cout<<hungarian()<<"\n";
    }
    return 0;
}
