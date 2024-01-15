#include<iostream>//ac
#include<vector>
#include<algorithm>
using namespace std;

//题解：反向建边+dfs
//因为需要判断每个点可以到达的最大点
//那么从大的点开始反向dfs遍历，能到达的点对应的值都为当前最大点

const int MAXN = 1e5+5;
int num[MAXN],vis[MAXN];//num记录当前点可到达的最大点，vis判断当前点是否走过
vector<int> g[MAXN];//存图
void dfs(int root,int dot) {//root为此次dfs的起点，dot为当前执行的点
    for(int i = 0;i < g[dot].size();i++) {//遍历所有可到达点
        int to = g[dot][i];
        if(vis[to]) continue;//跳过已走过（先走结果即为最优）
        num[to] = max(num[to],root);//可到达点取最大（可能到达n点）！！！
        vis[to] = 1;//记录（无需撤回）！！！
        dfs(root,to);//继续遍历
    }
}
int main() {
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= n;i++) num[i] = i;//初始化为到达自己！！！
    for(int i = 1;i <= m;i++) {
        int a,b;
        cin>>a>>b;// a可到达b
        g[b].push_back(a);//反向建边！！！
    }
    for(int i = n;i >= 1;i--) dfs(i,i);//从大到小都遍历（能到达的反向记答案）
    for(int i = 1;i <= n;i++) cout<<num[i]<<" ";//输出结果
    return 0;
}
