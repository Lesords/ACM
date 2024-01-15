#include<iostream>//ac
#include<cstdio>
#include<algorithm>
using namespace std;

//题解：线性dp
//由于小轩传给小渊的路径从上往下看的话，也是向下向右
//所以即为从左上到右下，选择两条路径，求最大路径值总和，重复的话只能选一次
//常规做法是：以两个路径所到达的位置为状态，即 f[x1][y1][x2][y2]
//由于起点为(1,1)，所以对于路径数step有： step = x+y+2
//所以两个路径都可以以 步数,列位置 为状态，因为行位置可以直接计算
//即以  步数,第一个路径的列位置,第二个路径的列位置 为状态（降低一维
//又因为每个路径可以有两个选择，所以对于每个状态都有四种情况来转移得到
//然后特判下两个路径重叠即可
//目的状态：dp[n+m-2][m][m]

const int MAXN = 55;
int a[MAXN][MAXN],dp[MAXN*2][MAXN][MAXN];
int main() {
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            cin>>a[i][j];
        }
    }
    //从1开始，0开始的话会越界！！！
    //0位置为0，不需要计算
    for(int step = 1;step <= m+n-2;step++) {                //step从1开始！！！
        for(int i = 1;i <= m&&i <= step+1;i++) {            //i的范围不能超过step+1（即只向右走的范围
            for(int j = 1;j <= m&& j <= step+1;j++) {
                int ix = step+2-i;                          //计算对应的行位置
                int jx = step+2-j;
                //第一个路径是向下走：第二个向下走、向右走
                int one = max(dp[step-1][i][j], dp[step-1][i][j-1]);//分别计算！！！
                //第一个路径是向右走：第二个向下走、向右走
                int two = max(dp[step-1][i-1][j], dp[step-1][i-1][j-1]);
                dp[step][i][j] = max(one, two);             //四种情况分开求最值，否则会漏掉两种！！！
                if(i==j) dp[step][i][j] += a[ix][i];        //重合，只计算一次
                else {
                    dp[step][i][j] += a[ix][i]+a[jx][j];    //叠加两个位置的值
                }
            }
        }
    }
    cout<<dp[m+n-2][m][m];
    return 0;
}
