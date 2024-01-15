#include<iostream>//ac
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

//题解：利用bfs计算树的宽度和深度
//然后利用两次dfs求两个点的lca
//第一次向上dfs起点标记经过的节点，第二次向上dfs终点第一个碰到有标记的即为lca

const int MAXN = 105;
struct node{
    int dot,dep;//dot为节点编号，dep为节点深度
};
vector<int> g[MAXN];//建图
int n,s,t,num[MAXN],numd[MAXN],vis[MAXN],ans,cnt;//ans为lca，cnt用来访问的编号
//num记录对应深度的节点数，numd为对应节点的深度，vis记录对应节点的访问编号（lca
void cal(int rt,int &wid,int &dep) {//计算宽度和深度
    queue<node> q;
    q.push({rt, 1});//根节点
    wid = dep = 1;//初始化宽度和深度都为1
    numd[rt] = 1;//rt深度的数量为1
    while(!q.empty()) {
        node tmp = q.front();
        q.pop();
        for(int i = 0;i < g[tmp.dot].size();i++) {//遍历所有指向点
            int now = g[tmp.dot][i];
            if(numd[now]) continue;//跳过已计算深度的点（已遍历
            num[tmp.dep+1]++;//对应深度的数量++
            numd[now] = tmp.dep+1;//记录当前节点的深度
            q.push({now,tmp.dep+1});//入队
            dep = max(dep, tmp.dep+1);//更新最大深度
        }
    }
    for(int i = 2;i <= dep;i++) {//遍历所有深度，求最大宽度
        wid = max(wid, num[i]);
    }
}
void dfs(int dot,int flag) {//flag为0表示起点向上dfs，flag为1表示终点向上dfs找lca
    if(flag&&vis[dot]) {//特判当前点即为lca的情况（要么根据深度交换位置）！！！
        ans = dot;return;
    }
    for(int i = 0;i < g[dot].size();i++) {
        int now = g[dot][i];
        //跳过深度大于当前点的节点，即需要向上走
        if(numd[now]>numd[dot]) continue;
        if(flag&&vis[now]) {//计算lca时，第一个标记的节点即为lca
            ans = now;return;
        }
        if(!flag) vis[now] = ++cnt;//预处理时，标记节点号即可
        if(flag&&ans) return;//lca计算完，直接返回
        dfs(now,flag);//继续遍历
    }
}
void solve(int s,int t) {//计算s到t的lca
    vis[s] = ++cnt;//处理s起点
    dfs(s,0);//预处理
    dfs(t,1);//t向上寻找lca
}
int main() {
    cin>>n;
    for(int i = 1;i <= n-1;i++) {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);//建双向边
        g[v].push_back(u);
    }
    cin>>s>>t;
    int dep = 0,wid = 0;
    cal(1,wid,dep);//计算宽度和深度
    solve(s,t);//计算lca
    //距离向上两倍，向下一倍
    cout<<dep<<"\n"<<wid<<"\n"<<((numd[s]-numd[ans])*2+numd[t]-numd[ans]);
    return 0;
}
