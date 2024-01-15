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

//题意：从树中选个k个点，使得这k个点相互之间的距离相等，计算方案数
//题解：
//1. 如果只选择两个点的话，也就是说当k=2时，可以从树中任意选择两个点
//则这两个点定满足条件，方案数为 c(n,2) = n*(n-1)/2;
//2. 如果选择的点数大于2的话，也就是说k>2时
//那么一定存在一个点m处于每个点之间的路径之间，并且不被选择
//也可以说，以m为根节点，枚举m所有的子树，每个子树最多只能选择一个节点（也可不选）
//并且最多选择k个节点，并且所有的节点之间的LCA必须是根节点m
//所以可有做法如下：
//枚举所有点为根节点时，用num[i][j]记录每个节点i向下走j步所能到达的数量
//然后枚举所有的深度dep，计算当前根节点以dep距离选择k点的方案数
//令 dp[i][j] 为第i个子树，选择j个节点的方案数
//边界为：所有dp初始化为0，且dp[i][0] = 1 ，其中  1 <= i <= n
//转移过程： 对于每个子树有：不选，在num[son][dep]个节点中选择一个
//dp[i][j] = dp[i-1][j] + dp[i-1][j-1]*num[son][dep]
//注意：num[son][dep] 为当前儿子节点son，且深度为dep的节点数量
//相乘可能爆int，所以用ll，记得取模！！！
//目的状态：所有的 dp[子树数量][k] 相加取模

const int MAXN = 105;
const int MOD = 1e9+7;
vector<int> g[MAXN];//存边
int n,k;
ll num[MAXN][MAXN],dp[MAXN][MAXN];
void dfs(int now, int fa) {                     //当前点为now，父节点为fa
    num[now][0] = 1;                            //记录当前点
    for(int i = 0;i < g[now].size();i++) {      //遍历所有指向点
        int dot = g[now][i];                    //当前指向点
        if(dot==fa) continue;                   //重复，则跳过
        dfs(dot, now);                          //继续向下遍历
        for(int j = 1;j <= n;j++) {             //更新对应数量
            //当前now走 j 步相当于儿子节点dot走 j-1 步
            num[now][j] += num[dot][j-1];
        }
    }
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        cin>>n>>k;
        for(int i = 1;i <= n-1;i++) {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);//存边，双向边
            g[v].push_back(u);
        }
        if(k==2) {//特判选择2个节点的情况
            for(int i = 1;i <= n;i++) g[i].clear();//清空边！！！
            cout<<n*(n-1)/2<<"\n";
            continue;
        }
        ll ans = 0;
        for(int i = 1;i <= n;i++) {
            memset(num, 0, sizeof(num));//初始化所有数量为0
            dfs(i,-1);
            int siz = g[i].size();//子树数量
            for(int dep = 0;dep <= n;dep++) {//从0开始遍历深度
                memset(dp, 0, sizeof(dp));//初始化为0
                for(int j = 0;j <= siz;j++) dp[j][0] = 1;//边界为1
                for(int j = 1;j <= siz;j++) {//遍历所有子树
                    for(int k = 1;k <= j;k++) {//可以选择的数量不能超过子树数量！！！
                        int son = g[i][j-1];//下标从0开始，所以需-1
                        int val = num[son][dep];//当前子树可以选择的数量
                        //更新dp[j][k]，为 不选 和 选
                        dp[j][k] = (dp[j-1][k]+dp[j-1][k-1]*val%MOD)%MOD;
                    }
                }
                ans = (ans+dp[siz][k])%MOD;//累加和并取模
            }
        }
        cout<<ans<<"\n";
        for(int i = 1;i <= n;i++) g[i].clear();//清空边！！！
    }
    return 0;
}
