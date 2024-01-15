#include<iostream>//ac
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 105;

//题解：对于每天来说有三个状态：休息，运动，比赛 (0 1 2)
//那么可以根据当天情况来计算对应的状态即可

int a[MAXN],dp[MAXN][3];//dp[i][0|1|2]：为当前状态所休息的天数和
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
    memset(dp, 127, sizeof(dp));//求小值，则初始化大值
    dp[0][0] = dp[0][1] = dp[0][2] = 0;//临界点需为0
    for(int i = 1;i <= n;i++) {
        //当前休息，则前一天的状态不受限（三个状态都可，取小值 + 1）
        dp[i][0] = min(dp[i-1][0], min(dp[i-1][1],dp[i-1][2])) + 1;
        if(a[i]==1||a[i]==3) {//比赛
            //由于状态不能连续，所以取前一天的另外两个状态的较小值
            dp[i][2] = min(dp[i-1][0], dp[i-1][1]);
        }
        if(a[i]==2||a[i]==3) {//运动
            //由于状态不能连续，所以取前一天的另外两个状态的较小值
            dp[i][1] = min(dp[i-1][0], dp[i-1][2]);
        }
    }
    //终点三个状态的最小值即为答案
    printf("%d", min(dp[n][0], min(dp[n][1],dp[n][2])));
    return 0;
}
