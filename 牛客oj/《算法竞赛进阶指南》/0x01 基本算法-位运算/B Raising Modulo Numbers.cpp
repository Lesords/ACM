#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;

//题解：计算所有组合的和，然后取模即可

ll poww(ll a,ll b,ll p) {// a^b % p
    ll ans = 1%p;
    while(b) {
        if(b&1) ans = ans*a%p;
        b >>= 1;
        a = (a*a)%p;
    }
    return ans;
}
int main() {
    int t,n;
    cin>>t;
    while(t--) {
        ll a,b,p,ans = 0;
        cin>>p>>n;
        for(int i = 1;i <= n;i++) {
            cin>>a>>b;
            //累加 a^b%p 的值
            ans = (ans+poww(a,b,p))%p;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
