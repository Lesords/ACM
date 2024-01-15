#include<iostream>//ac
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

//题意：计算食物链的数量（即到达食物链顶端的路径数总和）
//题解：利用类似拓扑排序的思想，计算从食物链底端到达各点的路径数
//统计出度为0（食物链顶端）的点的路径数即为答案（入度为0的点路径数初始化为1）

const int MAXN = 5e3+5;
const int MOD = 80112002;
int in[MAXN],out[MAXN],dp[MAXN],n,m;
//in保存入度，out保存出度，dp[i]:从食物链底端到达i的路径数量
vector<int> g[MAXN];//保存食物链关系图
int main() {
    cin>>n>>m;
    for(int i = 1;i <= m;i++) {
        int a,b;
        cin>>a>>b;//a被b吃
        g[a].push_back(b);//记录关系图
        out[a]++,in[b]++;//记录对应的入度和出度
    }
    queue<int> q;
    int ans = 0;
    for(int i = 1;i <= n;i++) {
        if(!in[i]) dp[i] = 1,q.push(i);//入度为0入队列，路径数为1
    }
    while(!q.empty()) {
        int tmp = q.front();q.pop();
        for(int i = 0;i < g[tmp].size();i++) {//遍历所有指向点
            dp[g[tmp][i]] = (dp[g[tmp][i]]+dp[tmp])%MOD;//指向点更新路径数
            in[g[tmp][i]]--;//指向点入度--（出度不操作）
            if(in[g[tmp][i]]==0) {//若入度为0则继续判断是否需要入队列
                if(out[g[tmp][i]]) q.push(g[tmp][i]);//出度不为0才入队列
            }
        }
    }
    //食物链顶端不止一个，即出度为0不止一个！！！
    for(int i = 1;i <= n;i++) if(out[i]==0) ans = (ans+dp[i])%MOD;//答案累积
    cout<<ans<<endl;
    return 0;
}
