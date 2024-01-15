#include<iostream>//ac
#include<cstring>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;

//题解：根据所有情况把多行压成一行，进行dp求最大连续和
//所有情况可先遍历起点，然后每增加一行数据就进行一次一维dp

const int MAXN = 125;
int a[MAXN][MAXN],tmp[MAXN],dp[MAXN];//tmp存储压行后的值，dp用来求最大连续和
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++) cin>>a[i][j];
    int ans = -INF;//有负数
    for(int i = 1;i <= n;i++) {//i表示压行的起点
        memset(tmp,0,sizeof(tmp));
        for(int j = i;j <= n;j++) {//从起点i开始压行到终点n
            for(int k = 1;k <= n;k++) {//压行操作（每次只添加一行）
                tmp[k] += a[j][k];
            }
            memset(dp,0,sizeof(dp));//进行dp前需初始化
            for(int k = 1;k <= n;k++) {//求一维最大连续和
                dp[k] = max(dp[k-1]+tmp[k],dp[k]);
                ans = max(ans,dp[k]);//更新答案
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
