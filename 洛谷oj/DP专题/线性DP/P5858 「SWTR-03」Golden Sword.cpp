#include<iostream>//ac
#include<queue>
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;

//题解：线性dp+单调队列优化
//令 dp[i][j] 表示当前选择i原料，并且炼金锅中有j个原料时的耐久度
//由于原料耐久度有负数，所以需要将所有状态赋值为-INF
//边界状态：dp[0][0] = 0，即此时没有原料则耐久度为0
//状态转移：
// dp[i][j] = a[i]*j + min(dp[i-1][k]) (j-1<= k < j+s)
//当前原料耐久度 + 上一个状态的值
//由于每次只能取出s个原料，所以当前要么一个没取出(j-1)，要么取出了s个（j+s-1）
//因为 (j-1)+1 = j; (j+s-1) - s + 1 = j;（取出对应个数+当前一个）
//所以对于一个区间为s长度的dp状态取min值
//那么可以用单调队列来优化这个过程
//由于允许上一个j的数量比当前大，所有对于j的状态可以倒序计算！！！
//每次初始状态先放入本身位置的值，然后再进行判断是否有越界的，然后再放入j-1的值
//这样刚好满足了范围区间
//目的状态：max(dp[n][i])  1 <= i <= w

const int MAXN = 5e3+5;
struct node{
    int pos;//记录位置
    ll val;//记录值
};
ll dp[MAXN][MAXN],a[MAXN];
int main() {
    int n,w,s;
    cin>>n>>w>>s;
    for(int i = 1;i <= n;i++) cin>>a[i];
    for(int i = 0;i <= n;i++) {//赋值为最小值-INF
        for(int j = 0;j <= w;j++) dp[i][j] = -INF;
    }
    dp[0][0] = 0;//边界状态为0
    deque<node> de;//双端队列来实现单调队列
    for(int i = 1;i <= n;i++) {
        while(!de.empty()) de.pop_back();//清空队列
        //放入初始值，由于只能容纳w个，所以需要取较小值！！！
        de.push_back({min(i,w),dp[i-1][min(i,w)]});
        for(int j = min(i,w);j >= 1;j--) {//倒序计算，满足拿走若干个原料的条件
            //最多拿走s个原料后，不能超过j-1（预留一个给本身1），否则弹出
            //注意：需要判断队列是否为空！！！
            while(!de.empty()&&de.front().pos-s>j-1) de.pop_front();
            //由于当前添加的状态为dp[i-1][j-1]，所以将队列中所有比其小的弹出
            while(!de.empty()&&de.back().val<dp[i-1][j-1]) de.pop_back();
            de.push_back({j-1, dp[i-1][j-1]});
            dp[i][j] = a[i]*j+de.front().val;
        }
    }
    ll ans = -INF;//计算结果
    for(int i = 1;i <= w;i++) ans = max(ans, dp[n][i]);//取最大值
    cout<<ans;
    return 0;
}
