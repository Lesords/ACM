#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;

//��⣺���ÿ�����˼��Ĺ��ٳ�

ll multi(ll a,ll b,ll p) {//�����Ϊ b��a���
    ll ans = 0;
    while(b) {
        if(b&1) ans = (ans+a)%p;
        b >>= 1;
        a = (a<<1)%p;//a����
    }
    return ans;
}
int main() {
    ll a,b,p;
    cin>>a>>b>>p;
    cout<<multi(a,b,p);
    return 0;
}
