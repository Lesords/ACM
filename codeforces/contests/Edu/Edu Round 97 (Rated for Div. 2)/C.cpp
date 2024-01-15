#include<iostream>//ac
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<utility>
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;

//题解：线性dp
//由于最后结果需要最小，那么需要从小到大排序碟子需要花费的时间
//将 当前时间，已选择碟子 为状态
//初始化边界：
//先将全部赋值为INF，然后将每个时间点拿出0个碟子(dp[i][0])的状态修改为0
//那么可以顺着时间线转移方程了（两倍时间够转移
//令数组 dp[i][j]：表示在i时间已经拿出了j个碟子的最小值
//那么如果i时间前已经拿出了j个碟子的状态也可以包含在 dp[i][j]中
//即 dp[i][j] = min(dp[i][j], dp[i-1][j]) ！！！
//这是继承前面的状态
//那么对于当前有选择j碟子的话为：
//dp[i][j] = min(dp[i][j], dp[i-1][j-1] + abs(t[j]-i))
//结果状态：
//那么对于 每个时间点拿出了n个碟子的状态(dp[i][n]) 取最小值即可

const int MAXN = 205;
int t[MAXN],dp[MAXN<<1][MAXN];//第一维为时间，需两倍
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int q;
    cin>>q;
    while(q--) {
        int n;
        cin>>n;
        for(int i = 1;i <= n;i++) cin>>t[i];
        sort(t+1,t+1+n);                    //排序
        memset(dp,0x3f,sizeof(dp));         //赋值为INF
        for(int i = 0;i <= n*2;i++) dp[i][0] = 0; //边界状态为0，没拿出碟子
        for(int i = 1;i <= n*2;i++) {       //先时间，需要继承前面的时间，碟子无法继承！！！
            for(int j = 1;j <= n;j++) {     //遍历所有碟子
                dp[i][j] = min(dp[i][j], dp[i-1][j]);                   //继承前面的状态
                dp[i][j] = min(dp[i][j], dp[i-1][j-1]+abs(t[j]-i));     //当前选择
            }
        }
        int ans = INF;                                                  //遍历所有时间点
        for(int i = 1;i <= n*2;i++) ans = min(ans, dp[i][n]);           //取最小值即可
        cout<<ans<<'\n';
    }
	return 0;
}
