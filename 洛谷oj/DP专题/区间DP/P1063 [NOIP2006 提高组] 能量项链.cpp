#include<iostream>//ac
#include<algorithm>
using namespace std;

//题解：区间dp
//由于项链是环形，所以可以多添加一段来方便计算
//为了方便计算可以先维护每个珠子的头标记和尾标记的值
//那么对于每次合并，增加的能量为 取首的头标记*中间的尾标记*最后一个的尾标记
//需要注意的是两个珠子也需要合并，也就是len需要从1开始！！！
//以  [左边界,右边界]  为当前状态
//f[i][j]为[i,j]边界内聚合成一个珠子后释放的最大能量
//每次合并的能量取最大值 或者 直接以n为长度的所有区间取最大值

const int MAXN = 205;
int head[MAXN],tail[MAXN];//head为头标记，tail为尾标记
unsigned int dp[MAXN][MAXN];
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        cin>>head[i];
        head[i+n] = head[i];                    //多添加一段
    }
    tail[2*n] = head[1];                        //边界的尾标记
    for(int i = 1;i < 2*n;i++) {
        tail[i] = head[i+1];                    //计算尾标记
    }
    unsigned int ans = 0;
    for(int len = 1;len < n;len++) {            //先长度
        for(int i = 1;i+len <= 2*n;i++) {       //然后起点
            int j = i+len;                      //终点可以计算
            for(int k = i;k < j;k++) {          //遍历所有中间点，可以包括i但是不能包括j
                //否则 k+1 会大于j
                dp[i][j] = max(dp[i][j], dp[i][k]+dp[k+1][j]+head[i]*tail[k]*tail[j]);
                //此时中间点为k
//                ans = max(ans, dp[i][j]);
            }
        }
    }
    for(int i = 1;i <= n;i++) ans = max(ans, dp[i][i+n-1]);//两种都可
    cout<<ans;
    return 0;
}
