#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;
ll solve(ll x,ll y) {//�˻ᱬll����ô���԰Ѵ������ȥ��������
    ll ans = 1;
    while(x<=y) {//x*x ������ y/x
        y /= x;//���Ľ��Ҳ��һ���ģ�����
        ans++;
    }//ans��ʾx>y��ֵ
    return ans-1;//�������1
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        ll x,y;
        cin>>x>>y;//y==0!!!
        if(x<=1||y==0) cout<<"-1\n";//�����ڵ����
        else {
            cout<<solve(x,y)<<"\n";
        }
    }
    return 0;
}
