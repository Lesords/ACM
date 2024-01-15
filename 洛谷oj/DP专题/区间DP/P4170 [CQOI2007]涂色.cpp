#include<iostream>//ac
#include<cstring>
#include<algorithm>
using namespace std;

//题解：区间DP
//设 [左区间,右区间] 为状态
//dp[i][j]为区间[i,j]涂色所需要的最小次数
//边界状态：先初始化所有位置为无穷大，然后当i==j时，需要的次数为1
//状态转移：
//对于区间[l,r]而言，如果s[l]==s[r]，则可以在涂l或者r的时候，多涂一个位置
//即 dp[l][r] = min(dp[l-1][r], dp[l][r-1]) （妙
//如果不等，则可以遍历区间内所有点，然后将区间分成两个部分，取较小值
//目的状态：dp[1][n]

const int MAXN = 55;
int dp[MAXN][MAXN];
char s[MAXN];
int main() {
    memset(dp,0x3f,sizeof(dp));             //初始化为INF
    cin>>s+1;
    int n = strlen(s+1);
    for(int i = 1;i <= n;i++) dp[i][i] = 1; //边界为1
    for(int len = 1;len < n;len++) {        //先长度
        for(int i = 1;i+len <= n;i++) {     //后起点
            int j = i+len;                  //终点直接算
            //两个边界相等，直接取较小值
            if(s[i]==s[j]) dp[i][j] = min(dp[i-1][j], dp[i][j-1]);
            else {
                //否则取中间点，分割成两部分，然后取较小值
                for(int k = i;k < j;k++) {  //左边可包括，右边不可以（k+1
                    dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]);
                }
            }
        }
    }
    cout<<dp[1][n];
    return 0;
}
