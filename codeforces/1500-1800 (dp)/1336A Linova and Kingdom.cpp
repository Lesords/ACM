#include<iostream>//ac
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;

//题解：由于要使最后的快乐值最大，那么题目需要选择k个工业城市
//但是工业城市没有贡献值，所以可以转换为需要 n-k 个旅游城市
//那么对于每个旅游城市来讲：从工业城市转换为旅游城市的贡献值变化为
// siz[now]-1 - (dep[now]-1)   =>   siz[now]-dep[now]
//注：siz为子树的数量（包括自己），dep为深度（从1开始算）
//然后利用nth_element计算前n-k大的值即可
//n-k左右都是比n-k大的，故复杂度比排序好

const int MAXN = 2e5+5;
int a[MAXN],dep[MAXN],siz[MAXN],val[MAXN];
vector<int> g[MAXN];
bool cmp(int a,int b) {
    return a > b;
}
void dfs(int now, int fa) {
    dep[now] = dep[fa]+1;//深度为父亲+1
    siz[now] = 1;//当前子树数量为1（本身
    for(int dot:g[now]) {
        if(dot==fa) continue;//跳过父亲
        dfs(dot, now);//先遍历，后计算
        siz[now] += siz[dot];//子树数量
    }
    val[now] = siz[now]-dep[now];//计算now的贡献值
}
int main() {
    int n,k;
    cin>>n>>k;
    for(int i = 1;i < n;i++) {//只有n-1个数据！！！
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1,0);//从1开始遍历（根节点
    nth_element(val+1,val+n-k, val+n+1,cmp);//选择前n-k大的数据
    ll ans = 0;//数据爆int
    for(int i = 1;i <= n-k;i++) {
        ans += val[i];
    }
    cout<<ans<<"\n";
    return 0;
}
