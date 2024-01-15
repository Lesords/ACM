#include<iostream>//ac
#include<cstdio>
#include<algorithm>
using namespace std;

//题解：与传纸条类似
//三维区间dp
//利用 步数,第一个路径列位置,第二个路径列位置 为状态
//边界：起点坐标 (1,1)可能存在值，所以需要初始化起点位置
//即 dp[0][1][1] = a[1][1]
//转移：由四个状态转移过来，向下和向右（2*2组合
//注意判断下相等位置的情况即可
//目的状态：dp[n+n-2][n][n]

const int MAXN = 11;
int a[MAXN][MAXN],dp[MAXN*2][MAXN][MAXN];
int main() {
    int n,x,y,val;
    cin>>n;
    while(cin>>x>>y>>val&&x+y+val) {                    //都为0，则结束输入
        a[x][y] = val;                                  //存储对应位置的值
    }
    dp[0][1][1] = a[1][1];                              //边界值
    for(int step = 1;step <= n+n-2;step++) {            //初始化从1开始
        for(int i = 1;i <= n&&i <= step+1;i++) {        //不能超过step+1
            for(int j = 1;j <= n&&j <= step+1;j++) {
                int ix = step+2-i;                      //计算对应行位置
                int jx = step+2-j;
                int one = max(dp[step-1][i][j], dp[step-1][i][j-1]);//分别计算
                int two = max(dp[step-1][i-1][j], dp[step-1][i-1][j-1]);
                dp[step][i][j] = max(one, two);         //四种情况分别计算，否则会漏掉！！！
                if(i==j) dp[step][i][j] += a[ix][i];    //重叠只需计算一次
                else dp[step][i][j] += a[ix][i]+a[jx][j];//否则添加两个位置的值
            }
        }
    }
    cout<<dp[n+n-2][n][n];
    return 0;
}
