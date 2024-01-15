#include<iostream>//ac
#define ll long long
using namespace std;
ll ans = 0;
void solve(ll n) {
    ans++;//每次调用ans都要加1
    ll num = 2;//初始因子数量：1和本身
    //注意：i要用ll类型，否则会tle！！！
    for(ll i = 2;i*i <= n;i++) {//i*i为结束边界
        if(n%i==0) {
            num += (i!=n/i)?2:1;
        }//两个因子相同加1，否则加2
    }
    if(num==2) return;//只有两个因数时退出
    solve(num);
}
int main() {
    ll n;
    cin>>n;
    solve(n);
    cout<<ans<<endl;
    return 0;
}
