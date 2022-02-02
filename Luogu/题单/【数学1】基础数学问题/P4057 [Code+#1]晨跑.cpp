#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;

//题解：三个人的最小公倍数即为相遇

ll gcd(ll a,ll b) {
    return b==0?a:gcd(b,a%b);
}
ll lcm(ll a,ll b) {//爆int了！！！
    return a*b/gcd(a,b);
}
int main() {
    ll a,b,c;
    cin>>a>>b>>c;
    cout<<lcm(lcm(a,b),c);
    return 0;
}
