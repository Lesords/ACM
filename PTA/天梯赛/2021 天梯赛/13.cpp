#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<stack>
#include<string>
#include<queue>
#include<utility>
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;
const int MAXN = 1e5+5;
struct node {
    int u,c,d;
};
vector<node> g[MAXN];
int mon[MAXN],ans,vis[MAXN],n,m,q;
void dfs(int pos,int cost,int hui,int hcost) {
    if(pos>n) return;
    if(cost+hcost/hui>ans) return;
    if(pos==n) {
        ans = min(ans,cost+hcost/hui);
        return;
    }
    for(int i = 0;i < g[pos].size();i++) {
        node now = g[pos][i];
        if(vis[now.u]) continue;
        vis[now.u] = 1;
        if(hui!=1) dfs(now.u,cost,hui,hcost+now.d);
        else dfs(now.u,cost+now.c,hui,hcost);
        vis[now.u] = 0;
    }
    if(hui==1) {
        dfs(pos,cost,mon[pos],hcost);
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>q;
    for(int i = 1;i <= m;i++) {
        int u,v,c,d;
        cin>>u>>v>>c>>d;
        g[u].push_back({v,c,d});
    }
    for(int i = 1;i <= n;i++) {
        cin>>mon[i];
    }
    int tt,tval;
    for(int i = 1;i <= q;i++) {
        cin>>tt>>tval;
        mon[tt] = tval;
        ans = INF;
        for(int i = 1;i <= n;i++) vis[i] = 0;
        vis[1] = 1;
        dfs(1,0,1,0);
        cout<<ans<<"\n";
    }
    return 0;
}
