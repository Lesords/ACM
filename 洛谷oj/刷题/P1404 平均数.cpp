#include<iostream>//ac
#include<algorithm>
#define INF 0x3f3f3f3f3f3f3f3f
#define ll long long
using namespace std;

//题解；二分答案
//利用数列中最小值为左边界，最大值为右边界
//然后二分这个区间，判定是否满足条件
//对于判定函数而言，我们可以将所有数值减去当前平均数val
//如果出现大于等于m的区间值大于等于0，即满足条件
//前缀和相减即为区间值
//由于区间可以大于m，所以可以一直记录满足区间位置的最小值，然后相减判断即可！！！
//注：由于最后结果为平均数的1000倍，所以可以提前将所有数字*1000

const int MAXN = 1e5+5;
ll n,m,a[MAXN],sum[MAXN];//a为原数组，sum为前缀和数组
bool judge(int val) {
    for(int i = 1;i <= n;i++) {
        //a[i]-val为当前位置的值
        sum[i] = a[i]-val + sum[i-1];//计算前缀和
    }
    ll minn = INF;//初始化为INF
    for(int i = m;i <= n;i++) {//至少m长，所以以m为起点
        minn = min(minn, sum[i-m]);//可以大于m长度，所以取min
        if(sum[i]-minn>=0) return true;//相减大于等于0，即满足条件
    }
    return false;//否则不满足条件，返回false
}
int main() {
    cin>>n>>m;
    ll l = 0, r = 0, ans = 0;
    for(int i = 1;i <= n;i++) {
        cin>>a[i],a[i]*=1000;//扩大1000倍
        r = max(r, a[i]);//取最大值
        l = min(l, a[i]);//取最小值
    }
    while(l<=r) {
        ll mid = (l+r)>>1;
        if(judge(mid)) ans = mid, l = mid+1;//满足条件，扩大区间
        else r = mid-1;//否则缩小
    }
    cout<<ans<<"\n";
    return 0;
}
