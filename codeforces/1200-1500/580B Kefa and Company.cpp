#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;

//题解：根据钱的大小进行排序，利用双指针计算钱为d范围内的朋友因素和
//可以用前缀和来计算朋友区间因素和

const int MAXN = 1e5+5;
struct node{
    ll money, fact;
    friend bool operator < (node a,node b) {
        return a.money < b.money;
    }
}a[MAXN];
ll sum[MAXN];
int main() {
    ll n,d;
    cin>>n>>d;
    for(int i = 1;i <= n;i++) {
        cin>>a[i].money>>a[i].fact;
    }
    sort(a+1,a+n+1);//排序
    for(int i = 1;i <= n;i++) sum[i] = sum[i-1] + a[i].fact;//前缀和
    ll ans = 0;
    ll l = 1,r = 1;
    while(r<=n) {//r为末尾条件
        if(a[r].money-a[l].money<d)//在d的范围内时（不包括d！！！）
            while(r+1<=n&&(a[r+1].money-a[l].money)<d) r++;//下一个也满足d
        else while(a[r].money-a[l].money>=d) l++;//当前不满足，则l右移
        ans = max(ans, sum[r]-sum[l-1]);//取 [l,r] 区间和的较大值
        r++;//移动r来继续计算（因为此时[l,r]一定满足条件）
    }
    cout<<ans;
    return 0;
}
