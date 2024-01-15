#include<iostream>//ac
#include<cstring>
#include<algorithm>
using namespace std;

// 题解：线性dp
// 令dp[i][j]表示以i为最后一个数，并且公差为j的方案数
// 初始化所有状态都为0
// 转移过程：从前到后遍历所有的i，然后对于所有的i倒序遍历j(1 <= j <= i-1)
// dp[i][dif] = (dp[i][dif] + dp[j][dif] + 1)%MOD
// 其中多加1表示j位置可以与i组成一次方案，因为dp记录的是长度至少为2的数列
// 所以dp[j][dif]中并不包括j本身，因此转移到dp[i][dif]中需要多加1
// 结果计算：
// 长度为1和2的数列另外计算：累加i，即为i本身（长1，值1），i与前面(i-1)组合（长2，值(i-1)）
// 剩余的：对于每次的i，累加前面dp[j][dif]，因为dp[j][dif]为长度至少为2的数列方案数
// 包括i即为长度至少为3的数列方案数
// 注意：由于公差有负数情况，所有需要两倍空间和偏移量
// j正序倒序都可，不影响结果！！！

const int MAXN = 1e3+5;
const int MAXM = 2e4;
const int MOD = 998244353;
int h[MAXN],dp[MAXN][MAXM*2+10];
int main() {
    int n,ans = 0;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        cin>>h[i];
    }
    for(int i = 1;i <= n;i++) {
        ans = (ans+i)%MOD;//长度为1和2的方案数，1 + (i-1)
//        for(int j = i-1;j >= 1;j--) {//也可倒序
        for(int j = 1;j < i;j++) {//遍历前面所有位置，累加对应位置公差的方案数
            int dif = h[i] - h[j]+MAXM;//公差+偏移量
            ans = (ans+dp[j][dif])%MOD;//累加结果
            dp[i][dif] = (dp[i][dif] + dp[j][dif]+1)%MOD;//统计i位置对应偏差的方案数
            //j的值小于i，所以i累加对结果不受影响
            //+1为 i和j 匹配的方案
        }
    }
    cout<<ans;
    return 0;
}
