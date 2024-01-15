#include<iostream>//ac (二分答案)
#include<algorithm>
#define ll long long
using namespace std;
const int MAXN = 1e6+5;
int a[MAXN],n,m,maxx;
bool check(ll mid) {
    ll res = 0;
    for(int i = 1;i <= n;i++) {
        if(a[i]>=mid) res+=a[i]-mid;
    }//判断砍掉的树是否满足条件
    return res>=m;
}
int main() {
    cin>>n>>m;
    for(int i = 1;i <= n;i++) {
        cin>>a[i];
        maxx = max(maxx,a[i]);//最长的树即为最大可能值
    }
    ll l = 0,r = maxx,ans = 0;
    while(l<=r) {//二分
        ll mid = (l+r)/2;
        if(check(mid)) ans = mid, l = ans+1; //更新ans
        else r = mid-1;
    }
    cout<<ans<<endl;
    return 0;
}
