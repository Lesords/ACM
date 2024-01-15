#include<iostream>//ac 并查集
#include<cstring>
#include<algorithm>
using namespace std;

//题解：利用并查集把道路连接的两个城镇归为一个大的独立城镇
//最后再判断有多少个独立城镇即可，边数即为 城镇数-1

const int MAXN = 1e3+5;
int fa[MAXN];
int getf(int x) {//路径压缩
    return x==fa[x]?x:fa[x]=getf(fa[x]);
}
int main() {
    int n,m;
    while(cin>>n>>m&&n) {
        for(int i = 1;i <= n;i++) fa[i] = i;//初始化
        for(int i = 1;i <= m;i++) {//m条路连接
            int x,y;
            cin>>x>>y;
            x = getf(x);
            y = getf(y);
            if(x!=y) fa[y] = x;//祖先不一样，则向左合并
        }
        int ans = 0;//记录独立的点数
        for(int i = 1;i <= n;i++) ans += fa[i]==i;//没有合并的都为独立点
        //合并的祖先节点也算一个独立点（大的独立点）
        cout<<ans-1<<"\n";//ans个点最少的边连接数量为 ans-1
    }
    return 0;
}
