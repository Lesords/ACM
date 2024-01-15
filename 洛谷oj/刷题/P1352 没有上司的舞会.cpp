#include<iostream>//ac 树形dp
#include<vector>
#include<algorithm>
using namespace std;

//题解：树形dp，就是在dfs的过程中进行状态转移（可理解为树上解数塔）
//每个职员只有两个状态，0和1（去和不去）
//唯一的约束是 直接上司与职员
//利用约束进行建图，然后找关系图的根节点（没有直接上司的人）进行dfs

const int MAXN = 6e3+5;
int dp[MAXN][2];//dp[i][0]: i职员不去的值，dp[i][1]：i职员去
vector<int> g[MAXN];//保存上司底下的职员
bool is_root[MAXN],vis[MAXN];
//is_root判断当前是否为关系的根，vis表示当前点是否计算过
void dfs(int pos) {
    vis[pos] = 1;//标记当前点，表示已经过
    for(int i = 0;i < g[pos].size();i++) {//遍历所有下属
        int now = g[pos][i];
        if(vis[now]) continue;//跳过已计算过的
        dfs(now);//先dfs后计算状态
        //下属对于上司而言，都是累加的状态！！！
        dp[pos][0] += max(dp[now][0], dp[now][1]);//当前职员不去，则下属可以去也可以不去
        dp[pos][1] += dp[now][0];//当前职员去，则下属只能不去
    }
}
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>dp[i][1];//存储的值即为 当前职员去的状态值
    //输入的值也可理解为初始状态
    for(int i = 1;i < n;i++) {
        int l,k;
        cin>>l>>k;//k是l的上司
        is_root[l] = 1;//标记下属
        g[k].push_back(l);//上司对应的底下职员
    }
    for(int i = 1;i <= n;i++) {
        if(!is_root[i]) {//遍历所有点，寻找未标记过的即为根
            dfs(i);
            cout<<max(dp[i][0], dp[i][1])<<"\n";//当前职员的两个状态取最值
            return 0;
        }
    }
}
