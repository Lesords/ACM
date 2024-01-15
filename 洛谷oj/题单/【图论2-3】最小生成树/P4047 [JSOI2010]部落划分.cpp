#include<iostream>//ac
#include<cmath>
#include<algorithm>
#define two(x) (x)*(x)
using namespace std;

//题解：首先计算所有野人之间的距离
//由于这些野人分成了k个部落，那么可以理解为将一颗生成树分成k个部分
//由于一颗n个点的生成树需要连接 n-1 条边
//将生成树分成k个部分需要扣除 k-1 条边
//将野人当成一个点，所以对这些点需要连接 (n-1) - (k-1) = n-k 条边即可
//由于题目需要求的是两个部落之间的最小距离
//那么这个最小距离即为我们分割时的最小边，即为最小生成树中 n-k+1 小的边
//也就是说，我们选择了 n-k 条最小的边，但是 n-k+1 小的边没选
//即成为了分割部落的那条边

const int MAXN = 1e3+5;
struct node{
    int u,v;
    double w;
    friend bool operator < (node a,node b) {
        return a.w < b.w;//边权从小到大排序
    }
}a[MAXN*MAXN];
int dis[MAXN];//记录祖先
double x[MAXN],y[MAXN];//记录坐标
double cal(int i,int j) {//计算i到j的距离
    return sqrt(two(x[i]-x[j])+two(y[i]-y[j]));
}
int getf(int p) {//寻找p的祖先（路径压缩
    return dis[p]==p?p:dis[p]=getf(dis[p]);
}
int main() {
    int n,k,cnt = 0;//cnt记录边的数量
    cin>>n>>k;
    for(int i = 1;i <= n;i++) {
        cin>>x[i]>>y[i];
        dis[i] = i;//初始化祖先为本身
    }
    for(int i = 1;i <= n;i++) {
        for(int j = i+1;j <= n;j++) {
            //只取一个方向的边（因为i到j的距离等于j到i的距离）
            a[++cnt] = {i,j,cal(i,j)};
        }
    }
    sort(a+1,a+1+cnt);
    int num = 0;//num为已经选择的边的数量
    double ans = 0;//ans为部落之间的最短距离
    for(int i = 1;i <= cnt;i++) {
        node tmp = a[i];
        if(getf(tmp.u)!=getf(tmp.v)) {//若两个点还未连接
            dis[getf(tmp.u)] = dis[getf(tmp.v)];//向左合并
            num++;//数量++
            if(num==n-k+1) {//当前为 n-k+1 小的边时，即为部落间的最短距离
                ans = a[i].w;
                break;
            }
        }
    }
    printf("%.2f",ans);
    return 0;
}
