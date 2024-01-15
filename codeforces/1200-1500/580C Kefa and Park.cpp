#include<iostream>//ac
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN = 1e5+5;

//题解：dfs遍历所有到叶子的路径，计算路径中连续出现猫的数量是否大于m
//若大于m，则去掉（剪枝），剩余的叶子节点都满足条件

int cat[MAXN],ans,n,m;
vector<int> g[MAXN];//存边
void dfs(int pos,int fa,int num) {//当前位置，上一个位置，当前猫的连续数量
    int flag = 0;//判断是否为叶子节点
    for(int i = 0;i < g[pos].size();i++) {
        int now = g[pos][i];
        if(now==fa) continue;//跳过父节点
        flag = 1;//需要判断上一个位置是否有猫，有则累加，无则重计
        int tnum = cat[pos]?(num+cat[now]):cat[now];//注意括号！！！
        if(tnum>m) continue;//猫的连续数量超过条件
        dfs(now, pos,tnum);
    }
    if(flag) return ;//不为0即不是叶子节点
    if(num<=m) ans++;//满足条件的叶子节点累加即可
}
int main() {
    cin>>n>>m;
    for(int i = 1;i <= n;i++) cin>>cat[i];
    for(int i = 1;i < n;i++) {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1,0,cat[1]);//初始化
    cout<<ans;
    return 0;
}
