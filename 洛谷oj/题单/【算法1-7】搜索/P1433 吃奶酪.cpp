#include<iostream>//ac
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define INF 0x3f3f3f3f
#define two(x) (x)*(x)
using namespace std;

//题解：状态压缩DP
//先计算所有点之间的距离
//利用二进制存储已经经历过的奶酪位置
//然后进行DP

const int MAXN = 17;
double x[MAXN],y[MAXN],dis[MAXN][MAXN],f[MAXN][1<<15];//x、y数组记录坐标
//dis为记录两点之间的距离
//f[i][j]：到达i点状态为j的最小距离
double cal(int i,int j) {//计算i到j的距离
    return sqrt(two(x[i]-x[j]) + two(y[i]-y[j]));
}
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        cin>>x[i]>>y[i];
    }
    for(int i = 0;i <= n;i++) {             //计算两点间的距离
        for(int j = i+1;j <= n;j++) {
            dis[j][i] = dis[i][j] = cal(i,j);
        }
    }
    memset(f,0x7f,sizeof(f));               //赋值为0x7f才为最大值！！！
    for(int i = 1;i <= n;i++) {             //边界状态
        f[i][1<<(i-1)] = dis[0][i];         //只到达i点的距离
    }
    for(int k = 1;k <= (1<<n)-1;k++) {      //遍历所有状态
        for(int i = 1;i <= n;i++) {         //从j点到i点！！！
            if((k&(1<<(i-1)))==0) continue; //i点还没有遍历过，跳过
            for(int j = 1;j <= n;j++) {
                if(i==j) continue;          //跳过相同点
                // == 优先级比 & 大，所以需要加括号！！！
                if((k&(1<<(j-1)))==0) continue;//j点还没有遍历过，跳过！！！
                //从 到达j点但还没到达i点 的状态 + i点到j点的距离
                f[i][k] = min(f[i][k],f[j][k-(1<<(i-1))]+dis[i][j]);
            }
        }
    }
    double ans = INF;                       //初始化为最大值
    for(int i = 1;i <= n;i++) {
        ans = min(ans, f[i][(1<<n)-1]);     //到达i点且所有点都访问过
    }
    printf("%.2f",ans);
    return 0;
}
