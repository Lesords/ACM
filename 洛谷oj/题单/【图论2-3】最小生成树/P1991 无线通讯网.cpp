#include<iostream>//ac
#include<cstdio>
#include<cmath>
#include<algorithm>
#define two(x) (x)*(x)
using namespace std;

//题解：由于卫星电话之间的距离为0，所以远的优先用卫星电话
//那么对于本题而言，可以理解成将一个生成树分成若干个部分
//每个部分都有一个卫星电话，所以可以在生成树中把最长的几个边分割掉
//对于s个卫星电话，则可以分割s-1条边（将s-1条设为0）
//对于p个哨所，则需要p-1条边
//所以对于生成树来说只需要取 (p-1)-(s-1) 条边
//即对原图做Kruskal算法，取(p-1)-(s-1)条边就结束
//注意：求得是最大的边权值，而不是总和！！！

const int MAXN = 505;
struct node{
    int u,v;
    double w;
    friend bool operator < (node a,node b) {
        return a.w < b.w;//优先边权小的
    }
}a[MAXN*MAXN];
double x[MAXN],y[MAXN];//记录坐标
int dis[MAXN];//记录祖先
double cal(int i,int j) {//计算i到j的距离
    return sqrt(two(x[i]-x[j])+two(y[i]-y[j]));
}
int getf(int p) {//寻找p的祖先，路径压缩
    return dis[p]==p?p:dis[p]=getf(dis[p]);
}
int main() {
    int s,p,cnt = 0;//cnt记录边数
    cin>>s>>p;
    for(int i = 1;i <= p;i++) cin>>x[i]>>y[i];
    for(int i = 1;i <= p;i++) {
        for(int j = i+1;j <= p;j++) {
            //只取一个方向的边
            a[++cnt] = {i,j,cal(i,j)};//存边
        }
        dis[i] = i;//初始化祖先为本身
    }
    sort(a+1,a+1+cnt);
    double ans = 0;
    int num = (p-1)-(s-1);//需要计算的边数
    for(int i = 1;i <= cnt;i++) {//遍历所有边
        node tmp = a[i];
        if(getf(tmp.u)!=getf(tmp.v)) {//若不在生成树中，则连接
            dis[getf(tmp.u)] = dis[getf(tmp.v)];
            num--;//边数--
            if(num==0) {//为0说明没得选了，更新答案后结束
                ans = tmp.w;//当前边权即为最大边权值
                break;
            }
        }
    }
    printf("%.2f",ans);
    return 0;
}
