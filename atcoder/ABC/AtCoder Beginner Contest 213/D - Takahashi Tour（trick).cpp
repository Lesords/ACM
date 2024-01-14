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
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

//题解：直接根据题意模拟
//当前所有点都访问完之后再遍历原来的父节点的时候
//由于父节点遍历完之后就会把边删了！！！
//所以再次遍历父节点对实际的影响不大（下次遍历直接忽略其他所有边）

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
vector<int> ans;
priority_queue<int, vector<int>, greater<int> > g[MAXN];//存边
int vis[MAXN],fa[MAXN];//vis记录是否访问过，fa记录当前点的父节点（即第一次访问时的父节点
void dfs(int pos) {
    ans.push_back(pos);//记录答案
    int flag = 0;//flag记录是否还有点未访问
    //用vector会t，因为会一直遍历边
    //但是优先队列不会，因为它直接把边删了
    while(!g[pos].empty()) {
        int now = g[pos].top();
        g[pos].pop();//把访问过的边直接删除！！！
        if(vis[now]) continue;//跳过已访问的点
        vis[now] = 1;//标记当前点已访问
        fa[now] = pos;//记录对应点的父节点
        dfs(now);
        flag = 1;//存在边未访问
    }
    if(pos==1&&flag==0) return;//当前为1，并且无指向点未访问，直接返回
    if(flag==0) dfs(fa[pos]);//这是直接按照题意模拟，会多遍历一次
}
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1;i < n;i++) {
        int u,v;
        scanf("%d%d", &u,&v);
        g[u].push(v);
        g[v].push(u);
    }
    vis[1] = 1;//标记起点
    dfs(1);
    for(auto v:ans) {
        printf("%d ", v);
    }
	return 0;
}
