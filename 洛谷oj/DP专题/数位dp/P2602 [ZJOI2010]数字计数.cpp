#include<iostream>//ac
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;

//题解：数位dp
//对于每个数（0~9）进行一次数位dp
//由于前面的数码出现的次数 会影响到最后结果
//所以将 前面的数码出现的次数 设为dp的第二维状态
//然后记录对应结果，输出相减值即为答案

ll a[20],dp[20][20],ans[3][10];
//ans[0][0...9]:第一次计算的值 的对应数码出现的次数
//ans[1][0...9]:第二次计算的值 的对应数码出现的次数
//dp[i][j]:非受限情况下，当前为i位置，前面已经填了j个对应数码的结果
int now;
//pos为当前位置，lim为是否受限，zero为是否有前导零，now为当前数码，num为当前数码出现次数
ll dfs(int pos, bool lim, bool zero, int now,ll num) {
    if(pos==0) return num;//边界情况，直接返回对应结果num
    //非受限，且无前导0，对应状态已计算过，直接返回

    //有前导零对于数码0的计算有影响！！！
    //存在前导零，会将对应 状态 的结果记录为0
    //前面为0，当前的0无贡献，那么遍历到1-9的时候下一个存在0时对应贡献也为0（记忆化
    //例：记录00 会使 10 20 30 40 50 的贡献也为0
    //也就是说个位的0会被忽略

    if(!lim&&!zero&&dp[pos][num]!=-1) return dp[pos][num];
    ll ans = 0,add = 0;//ans记录最后结果，add表示当前位是否有贡献
    int siz = lim?a[pos]:9;//计算范围
    for(int i = 0;i <= siz;i++) {//遍历所有值
        //如果当前计算的数码为0，并且存在前导零且当前填的也为0时，贡献值为0！！！
        if(!now&&zero&&i==0) add = 0;
        else add = i==now;//否则判断是否为 now
        //lim参数：当前受限，并且值为a[pos]，则下一个位置也受限
        //zero参数：前面有前导零并且当前选的也是0
        ans += dfs(pos-1, lim&&i==a[pos], zero&&i==0, now, num+add);
    }
    //非受限，并且无前导零，记录对应状态值
    if(!lim&&!zero) dp[pos][num] = ans;
    return ans;
}
void solve(ll val) {//记录val的所有数位上的值
    int pos = 0;
    while(val) {
        a[++pos] = val%10;
        val /= 10;
    }
    //分别计算0-9的结果
    for(int i = 0;i <= 9;i++) {
        memset(dp, -1, sizeof(dp));//每次计算前，都需要初始化！！！
        //当前位置为pos，受限，存在前导零，当前数码为i，数码出现次数为0
        ans[now][i] = dfs(pos, 1, 1, i, 0);
    }
    now ^= 1;//now取反（换个位置记录结果，小技巧
}
int main() {
    ll a,b;
    cin>>a>>b;
    solve(b);
    solve(a-1);
    //差值即为结果
    for(int i = 0;i <= 9;i++) cout<<ans[0][i]-ans[1][i]<<" ";
    return 0;
}
