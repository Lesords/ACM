#include<iostream>//ac
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

//题解：dfs遍历所有奶牛，记录每个牧场奶牛出现的次数
//牧场奶牛出现的次数为k的即为目的牧场

const int MAXN = 1005;
vector<int> g[MAXN];
int num[MAXN],a[MAXN];
bool vis[MAXN];//记录已访问的点
void dfs(int dot) {//遍历所有可到达点
    vis[dot] = 1;
    for(int i = 0;i < g[dot].size();i++) {
        int now = g[dot][i];
        if(vis[now]) continue;
        num[now]++;//对应点数量++
        dfs(now);
    }
}
int main() {
    int k,n,m;
    cin>>k>>n>>m;
    for(int i = 1;i <= k;i++) cin>>a[i],num[a[i]]++;//初始点也需记录！！！
    for(int i = 1;i <= m;i++) {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);//存图
    }
    for(int i = 1;i <= k;i++) {//所有奶牛dfs
        memset(vis,0,sizeof(vis));//初始化标记数组
        dfs(a[i]);
    }
    int ans = 0;
    for(int i = 1;i <= n;i++) {//计算数量为k的点数量
        if(num[i]==k) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
