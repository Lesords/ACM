#include<iostream>//ac
#include<set>
#include<algorithm>
using namespace std;

//题解：由于所有东西的价格都为a，并且买个第I个，再买第J个只需要话Kij
//那么可以建立最小生成树，连接所有的边，然后再加个起点的值即可
//需要注意的是：优惠不一定比原价便宜！！！

const int MAXN = 505;
struct node{
    int u,v,w;
    friend bool operator < (node a,node b) {
        return a.w < b.w;//优先小的
    }
}a[MAXN*MAXN];
int dis[MAXN];//记录祖先
int getf(int p) {//寻找p的祖先，路径压缩
    return dis[p]==p?p:dis[p]=getf(dis[p]);
}
int main() {
    int n,m,cnt = 0;//cnt记录边数
    cin>>n>>m;
    for(int i = 1;i <= m;i++) {
        for(int j = 1;j <= m;j++) {
            int tmp;
            cin>>tmp;
            if(i<=j) continue;//只需要记录一半的边即可（无向边只需要记录一条
            if(tmp==0) continue;//跳过无优惠的边
            a[++cnt] = {i,j,tmp};
        }
        dis[i] = i;//初始化祖先为本身
    }
    sort(a+1,a+cnt+1);//排序
    int ans = n;
    for(int i = 1;i <= cnt;i++) {//总共只有cnt个边
        node tmp = a[i];
        if(getf(tmp.u)!=getf(tmp.v)) {//若还未在生成树中，则连接
            ans += tmp.w;
            dis[getf(tmp.u)] = dis[getf(tmp.v)];//向左结合
        }
    }
    cout<<min(n*m,ans);//生成树可能没有原价(n*m)便宜！！！
    return 0;
}
