#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;

//��⣺����������ϵĺͣ�Ȼ��ȡģ����

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
            //�ۼ� a^b%p ��ֵ
            ans = (ans+poww(a,b,p))%p;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
