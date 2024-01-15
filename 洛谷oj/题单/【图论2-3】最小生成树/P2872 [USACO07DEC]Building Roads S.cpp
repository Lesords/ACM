#include<iostream>//ac
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#define two(x) (x)*(x)
using namespace std;

//题解：Kruskal，将已经给定的边权值定为0
//然后计算所有点之间的距离，然后进行Kruskal即可

const int MAXN = 1e3+5;
const int MAXM = 1e6+1005;
struct node{
    int x,y;
    double z;
    friend bool operator < (node a,node b) {
        return a.z < b.z;//优先边权小的
    }
}a[MAXM];
int dis[MAXN];//记录祖先节点（是否已连接
double x[MAXN],y[MAXN];//记录坐标
double cal(int i,int j) {//计算i到j的距离
    return sqrt(two(x[i]-x[j])+two(y[i]-y[j]));
}
int getf(int p) {//计算p的祖先（路径压缩
    return dis[p]==p?p:dis[p]=dis[getf(dis[p])];
}
int main() {
    int n,m,cnt = 0;
    cin>>n>>m;
    for(int i = 1;i <= n;i++) {
        cin>>x[i]>>y[i];
        dis[i] = i;//初始化祖先为本身
    }
    for(int i = 1;i <= m;i++) {
        int x,y;
        cin>>x>>y;
        a[++cnt] = {x,y,0};//建边权为0的边
    }
    for(int i = 1;i <= n;i++) {//计算所有点之间的距离
        for(int j = 1;j <= n;j++) {
            if(i==j) continue;//跳过自身
            double val = cal(i,j);//计算i到j的距离
            a[++cnt] = {i,j,val};//添加边
        }
    }
    sort(a+1,a+cnt+1);//排序
    double ans = 0;//计算添加的边权和
    for(int i = 1;i <= cnt;i++) {
        node tmp = a[i];
        if(dis[getf(tmp.x)]!=dis[getf(tmp.y)]) {//若还未在生成树中
            ans += tmp.z;//添加边权值
            dis[getf(tmp.x)] = dis[getf(tmp.y)];//向左合并
        }
    }
    printf("%.2f",ans);
    return 0;
}
