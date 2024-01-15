#include<iostream>//ac
#include<deque>
#include<algorithm>
#define ll long long
using namespace std;

//题解：线性dp+单调队列优化
//由于题目要求不能超过k个连续的数字被选择
//那么可以理解为累加所有数字和，再减去每至多经历k个连续段后的数字
//令 dp[i] 为选择i当前这个数时，需要扣除的数字和
//边界状态：dp[0] = 0
//转移过程：dp[i] = a[i] + min(dp[j])  其中 i-k-1 <= j <= i-1
//也就是说最远的位置离i隔了k(即在i-k-1位置)个位置，最近的位置就在i前面！！！
//那么对于 i-k-1 <= j <= i-1 这个区间，可以做单调队列优化
//每次先判断当前操作数是否比队尾的值小，然后再踢出超过范围的值
//目的状态：max(sum-f[i])  其中 n-k <= i <= n

const int MAXN = 1e5+5;
ll a[MAXN],f[MAXN];
int main() {
    int n,k;
    ll sum = 0,ans = 0;
    cin>>n>>k;
    for(int i = 1;i <= n;i++) {
        cin>>a[i];
        sum += a[i];//累加和
    }
    deque<int> de;
    de.push_back(0);//边界给0，防止越界！！！
    for(int i = 1;i <= n;i++) {
        f[i] = a[i]+f[de.front()];//当前数+前面在范围内的最小值
        //因为单调队列里的值是f数组，所以先计算f的值！！！
        //如果当前值比队尾小，则将队尾弹出
        while(!de.empty()&&f[de.back()]>f[i]) de.pop_back();
        de.push_back(i);//放入当前值
        //队首的位置要满足下一个位置 i+1 的范围,即离下一个位置中间只能隔k个位置
        while(!de.empty()&&de.front()+k+1<i+1) de.pop_front();
    }
    for(int i = n-k;i <= n;i++) {//n-k后面刚好剩余k个位置！！！
        ans = max(ans, sum-f[i]);//取最大值
    }
    cout<<ans;
    return 0;
}
