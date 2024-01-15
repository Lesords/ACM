#include<iostream>//ac
#include<cstdio>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;

//题意：对一个节点选择删除k个叶子，问最多可以删除几次
//题解：利用拓扑排序的思想
//记录每个节点对应的指向点，以及入度
//那么先删除所有可以删除的叶子（入度为1），并记录对应父节点的入度以及父节点对应的删除数
//如果父节点的删除数为k的倍数（表示该节点底下有满足k个叶子），结果++
//如果刚好此时父节点的入度也为1，表示删除所有节点之后，父节点也可以删除
//若父节点不满足k个叶子，则不能入队（应为不满足k个叶子，删除不了对应叶子，则成不了新的叶子
//注意：用vis判断该节点是否删除过，因为k为1的时候，可能会重复删叶子！！！

const int MAXN = 2e5+5;
int in[MAXN],siz[MAXN],vis[MAXN];//in记录入度，siz为对应节点的删除数，vis记录这个点是否删除过
vector<int> g[MAXN];//存边
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        int n,k;
        cin>>n>>k;
        for(int i = 1;i <= n;i++) {         //初始化
            vis[i] = in[i] = siz[i] = 0;
            g[i].clear();
        }
        for(int i = 1;i < n;i++) {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);              //建边
            g[v].push_back(u);
            in[u]++,in[v]++;                //记录对应入度
        }
        queue<int> q;
        int ans = 0;
        for(int i = 1;i <= n;i++) {         //先将所有可以删除的叶子入队
            if(in[i]==1) {
                q.push(i);
            }
        }
        while(!q.empty()) {
            int now = q.front();            //now为可以删除的叶子编号
            vis[now] = 1;                   //标记
            q.pop();
            for(int i = 0;i < g[now].size();i++) {//遍历所有指向点
                int dot = g[now][i];
                if(vis[dot]) continue;      //跳过已删除的节点
                in[dot]--;                  //父节点的入度--
                siz[dot]++;                 //父节点的删除数++
                if(siz[dot]%k==0) {         //如果删除数满足k的倍数
                    ans++;                  //则操作数++
                    if(in[dot]==1) {        //此时还满足入度为1，则继续入队
                        q.push(dot);
                    }
                }
            }
        }
        cout<<ans<<"\n";
    }
	return 0;
}
