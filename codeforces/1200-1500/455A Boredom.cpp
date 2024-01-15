#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;

//题解：由于限制条件只有两个，前一个值和后一个值删除
//那么也就是说每次只能选择所有相同值的位置，然后差值在1的所有值都不能选
//那么可以对值的范围进行dp
//进行dp的时候可以不需要考虑后面，只需要考虑前面的限制
//初始化dp[0] = 0,dp[1] = num[1] ，计算从2开始
//每个值都只有两个状态：选和不选
//当前不选的值为： dp[i-1] (前一个选，会删除后面的，也就是后面不选)
//当前选的值为：   dp[i-2]+num[i]*i (i-1不选，那么i-2选，再加上当前的值)

const int MAXN = 1e5+5;
ll a[MAXN],dp[MAXN],num[MAXN];//dp[i]是选i值所得的最大值，num记录出现的次数
int main() {
    int n,maxx = 0;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        cin>>a[i];
        num[a[i]]++;//数量++
        maxx = max(maxx*1ll,a[i]);//计算最值
    }
    dp[0] = 0,dp[1] = num[1];//初始化
    for(int i = 2;i <= maxx;i++) {//遍历定义域范围
        dp[i] = max(dp[i-1], dp[i-2]+num[i]*i);
        //当前不选：上一个选
        //当前选：上一个不选->上上个选 + 当前值
    }//当前选和不选
    cout<<dp[maxx];//输出结果
    return 0;
}
