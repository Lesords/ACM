#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;

//题解：a[i]+a[j] > b[i]+b[j] 可转化为 a[i]-b[i] > -(a[j]-b[j])
//所以可以计算a[i]-b[i]的值，然后从后往前利用二分计算满足条件的位置

const int MAXN = 2e5+5;
ll a[MAXN];
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>a[i];
    for(int i = 1;i <= n;i++) {
        ll tmp;
        cin>>tmp;
        a[i] -= tmp;//计算相减的结果
    }
    sort(a+1,a+n+1);//排序
    ll ans = 0;//结果会爆int
    for(ll i = n;i >= 1;i--) {//从后往前查找，后面的值大
        if(a[i]<=0) break;//小于0，则直接结束（前面的更小）
        ll pos = upper_bound(a+1,a+i,-a[i])-a;//找到第一个大于 -a[i]的位置
        ans += i-pos;// [pos,i)的数可以满足条件（都大于-a[i]
    }
    cout<<ans<<"\n";
    return 0;
}
