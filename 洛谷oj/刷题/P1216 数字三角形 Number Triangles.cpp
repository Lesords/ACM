#include<iostream>//ac
#include<algorithm>
using namespace std;
const int MAXN = 1e3+5;
int a[MAXN][MAXN],dp[MAXN][MAXN];
int main() {
    int r;
    cin>>r;
    for(int i = 1;i <= r;i++) {
        for(int j = 1;j <= i;j++) {
            cin>>a[i][j];
        }
    }
    for(int i = 1;i <= r;i++) dp[r][i] = a[r][i];//初始化最底下一行
    for(int i = r-1;i >= 1;i--) {//从下往上遍历
        for(int j = 1;j <= i;j++) {
            // 当前值 + 底下较大值
            dp[i][j] = a[i][j] + max(dp[i+1][j],dp[i+1][j+1]);//下和下左
        }
    }
    cout<<dp[1][1];//最顶即为答案
    return 0;
}
