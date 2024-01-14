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

//题解：根据题意可知，我们需要使 边权值大的边 的贡献尽量多（WA
//反过来想，也就是说，对应的 边权值小的边 的贡献尽量小
//那么可以将边根据边权值从小到大排序
//每次判断边权左右两边各有多少点，贡献次数即为两者乘积
//由于每次计算 边权值小 的之后，会将边权值小的忽略掉
//那么我们可以理解为 将这条边删除，将对应 点集 合并起来
//那么这个操作我们可以用 并查集 来解决
//并查集来保存每个 点集 的数量，每次判断完一条边，则将对应点集合并起来

//WA思路：利用dfs计算所有边 两个朝向的点 的数量
//然后将所有边根据 边权值 从大到小排序
//然后每次选取 一条边，贡献次数为：两个对应点集的乘积
//然后将对应点指向的另外点 的点集删除（另外的边）
//WA原因是因为这样只会删除 对应儿子 节点的数量，对于其他后代节点没有更新！！！

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
struct node{
    int u,v,w;
    friend bool operator < (node a,node b) {
        return a.w < b.w;//根据边权值从小到大排序
    }
}edge[MAXN];
int dis[MAXN], siz[MAXN];//dis记录对应的祖先，siz记录对应的子集数量
int getf(int pos) {//寻找pos的祖先
    return pos==dis[pos]?pos:dis[pos] = getf(dis[pos]);
}
void Merge(int a,int b) {//向左合并
    a = getf(a);
    b = getf(b);
    if(a!=b) {
        dis[b] = a;//a为祖先！！！
        siz[a] += siz[b];
    }
}
int main() {
    fast;
    int n;
    cin>>n;
    //初始化祖先为本身，数量为1
    for(int i = 1;i <= n;i++) dis[i] = i, siz[i] = 1;
    for(int i = 1;i < n;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        edge[i] = {u,v,w};
    }
    sort(edge+1, edge+n);//从小到大排序
    ll ans = 0;
    for(int i = 1;i < n;i++) {
        node tmp = edge[i];
        tmp.u = getf(tmp.u);//获取对应的祖先
        tmp.v = getf(tmp.v);
        //左右点集乘积 即为当前边贡献次数
        ans += siz[tmp.u] *1ll* siz[tmp.v] * tmp.w;
        Merge(tmp.u ,tmp.v);//计算完之后合并
    }
    cout<<ans<<"\n";
	return 0;
}
