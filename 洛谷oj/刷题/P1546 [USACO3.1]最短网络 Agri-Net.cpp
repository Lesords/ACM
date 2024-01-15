#include<iostream>//ac
#include<vector>
#include<algorithm>
using namespace std;

//题解：利用vector存边，然后跑Kruskal即可

const int MAXN = 105;
struct node{
    int u,v,w;
    friend bool operator < (node a,node b) {
        return a.w < b.w;               //优先边权小的
    }
};
vector<node> g;                         //存图
int dis[MAXN];                          //存祖先
int getf(int pos) {                     //查询祖先
    return dis[pos]==pos?pos:dis[pos] = getf(dis[pos]);
}
int main() {
    int n,tmp;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            cin>>tmp;
            if(i==j) continue;          //跳过本身
            g.push_back({i,j,tmp});
        }
        dis[i] = i;                     //初始化祖先为本身
    }
    sort(g.begin(),g.end());            //按边权排序
    int ans = 0;
    for(int i = 0;i < g.size();i++) {   //遍历所有边
        node tmp = g[i];
        if(getf(tmp.u)!=getf(tmp.v)) {  //若还未在生成树中，则选择当前边
            ans += tmp.w;
            dis[getf(tmp.u)] = getf(tmp.v);
        }
    }
    cout<<ans;
    return 0;
}
