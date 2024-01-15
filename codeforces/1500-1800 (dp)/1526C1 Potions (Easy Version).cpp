#include<iostream>//ac
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;

//题解：线性dp
//令 dp[i][j] 为前i个选了j个的最大值
//边界：先将所有位置初始化为-1，然后dp[i][0] = 0 ,其中 0 <= i <= n
//状态转移：
//如果 dp[i-1][j-1] 不为负数，并且 dp[i-1][j-1]+a[i] >= 0
//更新 dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]+a[i])
//否则为 dp[i][j] = dp[i-1][j]
//目的结果，若当前更新后 dp[i][j] 不为负数，则 ans = max(ans, j)

const int MAXN = 2e3+5;
ll dp[MAXN][MAXN];
int a[MAXN];
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>a[i];
    memset(dp, -1, sizeof(dp));//初始化所有位置为-1
    int ans = 0;
    for(int i = 0;i <= n;i++) dp[i][0] = 0;//边界为0（什么都不选，值为0
    for(int i = 1;i <= n;i++) {//i为当前位置！！！
        for(int j = 1;j <= i;j++) {//当前选的个数
            //前一个值不能小于0，且当前和也不小于0（满足总是不小于0的条件
            if(dp[i-1][j-1]>=0&&dp[i-1][j-1]+a[i]>=0) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]+a[i]);//i是当前位置！！！
            }
            else dp[i][j] = dp[i-1][j];
            if(dp[i][j]>=0) ans = max(ans, j);//结果大于0，则利用j更新ans的值
        }
    }
    cout<<ans;
    return 0;
}
