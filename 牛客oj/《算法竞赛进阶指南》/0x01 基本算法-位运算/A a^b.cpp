#include<iostream>//ac
#define ll long long
using namespace std;

//��⣺�����ݣ��ǵ�ȡģ
//�ᱬint��������ll

ll poww(ll a,ll b,ll p) {
    ll ans = 1;
    while(b) {
        if(b&1) {
            ans = (ans*a)%p;
        }
        b >>= 1;
        a = (a*a)%p;
    }
    //���磻 5^0%1 ʱ����ȡģ���Ϊ1��ʵ�ʽ��Ϊ0
    return ans%p;//���Ҳ��Ҫȡģ������
}
int main() {
    ll a,b,p;
    cin>>a>>b>>p;
    cout<<poww(a,b,p);
    return 0;
}
