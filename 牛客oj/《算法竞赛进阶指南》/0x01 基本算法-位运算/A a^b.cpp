#include<iostream>//ac
#define ll long long
using namespace std;

//题解：快速幂，记得取模
//会爆int，所以用ll

ll poww(ll a,ll b,ll p) {
    ll ans = 1;
    while(b) {
        if(b&1) {
            ans = (ans*a)%p;
        }
        b >>= 1;
        a = (a*a)%p;
    }
    //例如； 5^0%1 时，不取模结果为1，实际结果为0
    return ans%p;//结果也需要取模！！！
}
int main() {
    ll a,b,p;
    cin>>a>>b>>p;
    cout<<poww(a,b,p);
    return 0;
}
