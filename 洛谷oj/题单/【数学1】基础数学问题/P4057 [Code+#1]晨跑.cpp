#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;

//��⣺�����˵���С��������Ϊ����

ll gcd(ll a,ll b) {
    return b==0?a:gcd(b,a%b);
}
ll lcm(ll a,ll b) {//��int�ˣ�����
    return a*b/gcd(a,b);
}
int main() {
    ll a,b,c;
    cin>>a>>b>>c;
    cout<<lcm(lcm(a,b),c);
    return 0;
}
