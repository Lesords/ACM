#include<iostream>//ac
#include<cstring>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;

//题解：根据floyd算法思想求解
//由于需要按照给定的查询顺序来输出两个村庄的最短路
//而且查询的时间顺序也是严格递增的
//所以可以按照时间顺序来更新对应的最短路（松弛操作）
//即将当前查询操作的时间前的所有村庄都更新
//因为村庄的重建时间也是 递增 的

const int MAXN = 205;
int a[MAXN],dis[MAXN][MAXN],n;//a保存重建时间，dis保存两点的距离
void update(int pos) {//更新所有可以由pos位置中转的路径
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            //跳过没有边的情况
            if(dis[i][pos]==INF||dis[pos][j]==INF) continue;
            dis[i][j] = min(dis[i][j], dis[i][pos]+dis[pos][j]);
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int m,q,now = 1;//now为当前操作的村庄编号
    cin>>n>>m;
    for(int i = 1;i <= n;i++) {//初始化
        for(int j = 1;j <= n;j++) {
            if(i==j) dis[i][j] = 0;//除了自身其他都为INF
            else dis[i][j] = INF;
        }
    }
    for(int i = 1;i <= n;i++) {
        cin>>a[i];//时间为递增的！！！
    }
    for(int i = 1;i <= m;i++) {
        int x,y,t;
        cin>>x>>y>>t;
        x++,y++;//由于题目中的编号从0开始，所以都需要+1！！！
        dis[x][y] = dis[y][x] = t;//无向边
    }
    cin>>q;
    for(int i = 1;i <= q;i++) {
        int x,y,t;
        cin>>x>>y>>t;
        x++,y++;//由于题目中的编号从0开始，所以都需要+1！！！
        while(now<=n&&a[now]<=t) {//now为当前村庄编号
            //当前查询的时间大于当前村庄的重建编号则更新
            update(now);
            now++;//移到下一个村庄
        }
        if(a[x]>t||a[y]>t) cout<<"-1\n";//有任一村庄未建完
        else {
            if(dis[x][y]==INF) cout<<"-1\n";//距离为INF说明中间有村庄未建完
            else cout<<dis[x][y]<<"\n";
        }
    }
    return 0;
}
