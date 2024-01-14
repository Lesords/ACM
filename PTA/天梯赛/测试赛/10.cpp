#include<iostream>//ac
#include<cstdio>
#include<cmath>
#include<string>
#include<stack>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<algorithm>
#define ll long long
using namespace std;
const int MAXN = 1e5+5;
int a[MAXN];
int main() {
    int n,p;
    cin>>n>>p;
    for(int i = 1;i <= n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    ll ans = 0;
    for(int i = 1;i <= n;i++) {
        int dif = abs(p-a[i]);// (dif,p+a[i]) 范围内可满足条件
        //从后面开始寻找满足条件的范围，这样不会重复！！！
        int left = upper_bound(a+1+i,a+1+n,dif)-(a+1+i);//第一个大于dif的位置
        int right = lower_bound(a+1+i,a+1+n,p+a[i])-(a+1+i);//第一份大于等于 p+a[i] 的位置
        ans += right-left;//由于left位置满足条件，right位置不满足条件，所以差值即为答案
    }
    cout<<ans;
    return 0;
}
