#include<iostream>//ac
#define ll long long
using namespace std;
ll ans = 0;
void solve(ll n) {
    ans++;//ÿ�ε���ans��Ҫ��1
    ll num = 2;//��ʼ����������1�ͱ���
    //ע�⣺iҪ��ll���ͣ������tle������
    for(ll i = 2;i*i <= n;i++) {//i*iΪ�����߽�
        if(n%i==0) {
            num += (i!=n/i)?2:1;
        }//����������ͬ��1�������2
    }
    if(num==2) return;//ֻ����������ʱ�˳�
    solve(num);
}
int main() {
    ll n;
    cin>>n;
    solve(n);
    cout<<ans<<endl;
    return 0;
}
