#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;
const int MAXN = 2e5+5;
int a[MAXN];
ll solve(ll val) {//从头开始，前面的逐个对于后面的，结果是加不是乘！！！
    return val*(val-1)/2;//为等差数列，求和公式即可
}
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>a[i];
    sort(a+1, a+n+1);
    int num_l = 1, num_r = 1;
    for(int i = 2;i <= n;i++) {//计算最小值的数量
        if(a[i]==a[1]) num_l++;
        else break;
    }
    for(int i = n-1;i >= 1;i--) {//计算最大值的数量
        if(a[i]==a[n]) num_r++;
        else break;
    }
    if(a[1]==a[n]) {//所有值相同，则用等差求和公式计算
        cout<<"0 "<<solve(num_l)<<"\n";
    }
    else cout<<a[n]-a[1]<<" "<<num_l*1ll*num_r<<"\n";//否则直接相乘即可
    return 0;
}
