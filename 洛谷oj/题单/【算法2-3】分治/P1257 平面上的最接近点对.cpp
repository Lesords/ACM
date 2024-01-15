#include<iostream>//ac
#include<cstdio>
#include<cmath>
#include<algorithm>
#define INF 0x3f3f3f3f
#define two(x) (x)*(x)
using namespace std;
const int MAXN = 1e4+5;

//题解：分治，将平面上的点先按照x升序，然后按照y升序
//每个将平面上的点分成左右两个部分
//划分的边界为区间只有一个点或两个点，一个点直接返回INF，两个点直接返回两个点之间的距离
//然后取左右区间较小的距离dis为标准，从中间点向两边扩张，距离小于等于dis的点放入集合中
//最后把集合中的点两两比较，取最小值

struct node{
    double x,y;
    friend bool operator < (node a,node b) {
        if(a.x!=b.x) return a.x < b.x;//先按横坐标排序，再按纵坐标排序
        return a.y < b.y;
    }
}a[MAXN];
int b[MAXN];//记录集合中的点的编号
double cal(int i,int j) {//计算i到j的距离
    return sqrt(two(a[i].x-a[j].x) + two(a[i].y-a[j].y));
}
double Merge(int l,int r) {//计算[l,r]区间内两点距离的最小值
    double dis = INF;
    if(l==r) return dis;//只有一个点，则无穷
    if(l+1==r) {//两个点则直接计算
        return cal(l,r);
    }
    int mid = (l+r)/2,cnt = 0;
    double ldis = Merge(l,mid);//计算左区间的最短距离
    double rdis = Merge(mid+1,r);//计算右区间的最短距离
    dis = min(ldis,rdis);//记得更新dis（不然返回值为中间集合的最小点距离）！！！
    //计算中间部分的点
    for(int i = l;i <= r;i++) {
        double tdis = fabs(a[i].x-a[mid].x);//以a[mid].x为中线
        if(tdis<=dis) {//小于等于dis则添加点编号
            b[++cnt] = i;
        }
    }
    for(int i = 1;i <= cnt;i++) {//计算集合内的点的距离
        for(int j = i+1;j <= cnt;j++) {
            dis = min(dis, cal(b[i],b[j]));//取较小值
        }
    }
    return dis;
}
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        double x,y;
        cin>>x>>y;
        a[i] = {x,y};//记录点
    }
    sort(a+1,a+1+n);//排序
    printf("%.4lf",Merge(1,n));
    return 0;
}
