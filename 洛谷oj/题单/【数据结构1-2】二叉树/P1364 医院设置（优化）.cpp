#include<iostream>//ac
#include<vector>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;

//题解：以1为根，将居民数当成节点数计算，计算每个点以当前点为根的子树大小
//在计算子树大小的时候可以一起计算 以根为医院所需要走的路程和
//然后对每个点求路径和，最后取最小值
//路径和的转移方程：f[now] = f[dot] + (siz[1]-siz[now]) - siz[now]
//其中f数组是存储路程和，siz为子树大小
//意为：本来到达dot的居民分成两种，now的子树节点，不是now的子树节点
//对于now的子树节点来说，少走了一步
//对于不是now的子树节点来说，多走了一步（dot->now）
//now的子树节点数为：siz[now]，不是now的子树节点数为：siz[1]-siz[now]
//其中：siz[1]即为总数

const int MAXN = 105;
vector<int> g[MAXN];//存图
int num[MAXN],f[MAXN],siz[MAXN],ans = INF;
//num记录城市的居民数，f记录以当前点为根的总距离，siz记录以当前点为根的子树大小
//dfs计算子树大小，并计算以1为根的总距离(1为起点，方便后面的转移)
void dfs(int dot,int fa,int dep) {//dot为当前节点，fa为父节点，dep为当前点的深度
    siz[dot] = num[dot];//初始化为当前点的居民数
    for(int i = 0;i < g[dot].size();i++) {
        int now = g[dot][i];
        if(now==fa) continue;//跳过父节点
        dfs(now, dot, dep+1);
        siz[dot] += siz[now];//累加子树大小
    }
    f[1] += num[dot]*dep;//累加dot到达1的路径和
}
//dp计算每个城市的路程和
void dp(int dot,int fa) {//dot为当前节点，fa为父节点
    for(int i = 0;i < g[dot].size();i++) {
        int now = g[dot][i];
        if(now==fa) continue;//跳过父节点
        f[now] = f[dot] + (siz[1]-siz[now]) - siz[now];//转移
        dp(now, dot);//继续向下计算（遍历每个点）
    }
    ans = min(ans, f[dot]);//取最小值
}
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        int u,v;
        cin>>num[i]>>u>>v;
        if(u) {//存在左儿子，则存边
            g[i].push_back(u);
            g[u].push_back(i);
        }
        if(v) {//存在右儿子，则存边
            g[i].push_back(v);
            g[v].push_back(i);
        }
    }
    dfs(1,0,0);//计算每个点子树大小
    dp(1,0);//计算每个点的路程和，并取最小值
    cout<<ans;
    return 0;
}
