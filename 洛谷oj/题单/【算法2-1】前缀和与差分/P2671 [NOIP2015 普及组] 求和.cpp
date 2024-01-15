#include<iostream>//ac
#include<algorithm>
using namespace std;

//题解：根据题意可得，有贡献的一组应为同为奇数或偶数位置的同色格子（y无用
//那么可以将所有的数据分为同色的两种位置即可，共2*m组
//每个组里面，两两都能有贡献
//那么可以先统计组内数据数量和总和
//贡献值为 编号和数字（没有颜色！！！
//根据公式可以有：
//score = (x+y)*(num[x]+num[y])
//      = x*num[x] + x*num[y] + y*num[x] + y*num[y]
//集合{i}的得分为：
//(i1*num[1]+i1*num[2]+i2*num[1]+i2*num[2]) + (i2*num[2]+i2*num[3]+i3*num[2]+i3*num[3])+···
//整理有： score[i_n] = i_n(num[1···n] + (n-2)*num[i_n])

//也就是说，对于元素中的每个值都有 乘 其他的num（共n-1个）
// i_n * num[i_n] 共有 n-1 个（一个个匹配了n-1次）

//所以在 i_n(num[1···n]) 中多出了一个 i_n * num[i_n]，
//那么在 i_n * num[i_n] 中需要减去一个为 (n-2) * i_n *num[i_n]

//即为 i_n * (num[1···n]) + i_n * num[i_n] * (n-2)
//化简为： i_n(num[1···n] + (n-2)*num[i_n])

const int MAXN = 1e5+5;
const int MOD = 10007;
int num[MAXN],color[MAXN],sum[MAXN][2],cnt[MAXN][2];
int main() {
    int n,m,ans = 0;
    cin>>n>>m;
    for(int i = 1;i <= n;i++) cin>>num[i];
    for(int i = 1;i <= n;i++) {
        cin>>color[i];
        cnt[color[i]][i%2]++;//统计数量
        sum[color[i]][i%2] = (sum[color[i]][i%2]+num[i])%MOD;//累加
    }
    for(int i = 1;i <= n;i++) {
        int tsum = sum[color[i]][i%2]%MOD;//当前组的数量
        int tnum = cnt[color[i]][i%2]%MOD;//当前组的总和
        ans = (ans+(i%MOD)*(tsum + (tnum-2)*num[i]%MOD)%MOD)%MOD;//取模！！！
    }
    cout<<ans;
    return 0;
}
