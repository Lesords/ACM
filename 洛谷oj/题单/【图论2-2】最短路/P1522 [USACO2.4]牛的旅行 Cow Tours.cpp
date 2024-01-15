#include<iostream>//ac
#include<cstdio>
#include<cmath>
#include<algorithm>
#define INF 0x3f3f3f3f
#define two(x) (x)*(x)
using namespace std;

//题意：给定n个牧区的坐标，以及这n个牧区的邻接矩阵关系（1为有边，0无边）
//由于刚好有两个牧场，所以在两个牧场中各选一个牧区连接，使得两个牧场联通之后
//的直径最小
//题解：先计算两个牧场内的各个牧区之间的最短路
//然后再选择一条连接两个牧区后牧场的直径最小的边，取两种情况的最大值即为牧场直径

const int MAXN = 155;
struct node{
    double x,y;
}a[MAXN];
double dis[MAXN][MAXN],maxdis[MAXN];//dis记录两个牧区之间的距离，maxdis记录当前牧区到达最远牧区的距离
double cal(int s,int e) {//计算s到e的距离
    return sqrt(two(a[s].x-a[e].x) + two(a[s].y-a[e].y));
}
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        cin>>a[i].x>>a[i].y;
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            char tmp;
            cin>>tmp;
            if(tmp=='1') {//1为有边
                dis[i][j] = cal(i,j);
            }
            else if(i!=j) dis[i][j] = INF;
        }
    }
    for(int k = 1;k <= n;k++) {//floyd求最短路
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= n;j++) {
                dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
            }
        }
    }
    double ans = 0,joint = INF;//ans先计算牧场内各个牧区到达最远的牧区距离
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            if(dis[i][j]!=INF) maxdis[i] = max(maxdis[i], dis[i][j]);//更新i可以到达的最远距离
            ans = max(ans, maxdis[i]);//更新ans
        }
    }
    for(int i = 1;i <= n;i++) {//寻找没有连通的两个点，即分别为两个牧场的牧区
        for(int j = 1;j <= n;j++) {
            if(dis[i][j]==INF) {//i和j不连通
                double val = cal(i,j);//计算i到j的距离
                joint = min(joint, maxdis[i]+val+maxdis[j]);//连通后的直径要取最小！！！
                //i可以到达的最远距离 + ij距离 + j可以到达的最远距离 = 连通后牧场的直径
            }
        }
    }//有可能连通之后的直径joint比单个牧场ans小，所以需要多取max
    printf("%.6f",max(ans,joint));
    return 0;
}
