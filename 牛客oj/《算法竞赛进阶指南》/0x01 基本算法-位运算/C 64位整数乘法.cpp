#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;

//题解：利用快速幂思想的龟速乘

ll multi(ll a,ll b,ll p) {//可理解为 b个a想加
    ll ans = 0;
    while(b) {
        if(b&1) ans = (ans+a)%p;
        b >>= 1;
        a = (a<<1)%p;//a翻倍
    }
    return ans;
}
int main() {
    ll a,b,p;
    cin>>a>>b>>p;
    cout<<multi(a,b,p);
    return 0;
}
