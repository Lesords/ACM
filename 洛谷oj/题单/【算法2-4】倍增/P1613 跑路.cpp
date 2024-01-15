#include<iostream>//ac
#include<cstring>
#include<algorithm>
using namespace std;

//题解：倍增+最短路
//利用倍增来预处理两个点是否可以在1s内到达
//然后利用floyd求最短路（最少花费时间）

int n,m;
int dis[55][55],f[55][55][55];
//dis[i][j]：表示i到j的距离
//f[i][j][k]：表示i到j存在距离为 2^k 的路
int main() {
    memset(dis,0x3f,sizeof(dis));//初始化为最大值
    cin>>n>>m;
    for(int i = 1;i <= m;i++) {//m条边（wa点）！！！
        int x,y;
        cin>>x>>y;
        dis[x][y] = 1;//x到y的花费的时间
        f[x][y][0] = 1;//倍增的边界
    }
    //倍增预处理可以一秒到达的点
    for(int i = 1;i < 50;i++) {//倍增范围
        for(int j = 1;j <= n;j++) {//中间点
            for(int k = 1;k <= n;k++) {//起点
                for(int u = 1;u <= n;u++) {//终点
                    //倍增思想：一个大区间等于两个小区间和
                    //2^i = 2^(i-1) + 2^(i-1)
                    if(f[k][j][i-1]&&f[j][u][i-1]) {
                        f[k][u][i] = 1;//记录路径
                        dis[k][u] = 1;
                    }
                }
            }
        }
    }
    //floyd求最短路（最少花费时间时间）
    for(int i = 1;i <= n;i++) {//中间点
        for(int j = 1;j <= n;j++) {//起点
            for(int k = 1;k <= n;k++) {//终点
                dis[j][k] = min(dis[j][k], dis[j][i]+dis[i][k]);
            }
        }
    }
    cout<<dis[1][n];
    return 0;
}
