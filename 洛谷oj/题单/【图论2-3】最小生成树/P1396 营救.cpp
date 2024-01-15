#include<iostream>//ac
#include<algorithm>
using namespace std;

//题解：由于求得是s到t道路中最大的边权值（尽量最小）
//那么可以利用Kruskal建生成树，如果当前边连接之后s与t联通
//那么当前边的边权即为结果（因为Kruskal的边权是从小到大选的

const int MAXN = 2e4+5;
struct node{
    int u,v,w;
    friend bool operator < (node a,node b) {
        return a.w < b.w;//优先边权小的
    }
}a[MAXN];
int dis[MAXN];//记录祖先
int n,m,s,t;
void init() {//初始化祖先为本身
    for(int i = 1;i <= n;i++) dis[i] = i;
}
int getf(int p) {//获取p的祖先，路径压缩
    return dis[p]==p?p:getf(dis[p]);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>s>>t;
    for(int i = 1;i <= m;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        a[i] = {u,v,w};//存边
    }
    sort(a+1,a+m+1);//排序
    int ans = 0;
    init();
    for(int i = 1;i <= m;i++) {
        node tmp = a[i];
        if(getf(tmp.u)!=getf(tmp.v)) {//不在生成树中，则连接
            dis[getf(tmp.u)] = dis[getf(tmp.v)];
        }
        if(getf(s)==getf(t)) {//s到t连通，则当前边权为结果
            ans = tmp.w;break;
        }
    }
    cout<<ans;
    return 0;
}
