#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;

//题解：除了n，其他都有一个位置可以连接，共n-1条边，形成一棵树
//对于树来说，再连接任意一条边都可以形成环
//对于题目来说，需要求环的数量，那么可以计算总的排列-没有环的数量
//最后会形成树的要么 单调递增 要么 单调递减 要么 递增到n再递减
//以n为标准，对于其他的n-1个数的放置选择都有两种，所以为2^(n-1)

const int MOD = 1e9+7;
ll poww(ll a,ll b) {//快速幂，求次方
    ll ans = 1;
    while(b) {
        if(b&1) ans = (ans*a)%MOD;
        a = (a*a)%MOD;
        b>>=1;
    }
    return ans;
}
int main() {
    int n;
    ll sum = 1;
    cin>>n;
    for(int i = 1;i <= n;i++) sum = (sum*i)%MOD;//所有的可能性
    cout<<(sum-poww(2,n-1)+MOD)%MOD;//扣除树的情况
    return 0;
}
