#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;

//��⣺ÿ�����̿������Ϊ��ȥһ����k��Ȼ��ÿ�ζ���ʣ��rest��ֵ
//��ôҲ����˵������ת��Ϊÿ�����rest��ֵ�����κ���Ա� ���к�һ���� ����

ll cal(ll n) {//���㹻��������ɾ���������һλ��ֵ��
    ll l = 1,r = n,ans = 0;//ansֵ����ȡ��
    while(l<=r) {
        ll mid = (l+r)>>1;
        //��ȥ���ܺ��õȲ�������͹�ʽ
        if((1+mid)*mid/2<=n) ans = mid,l = mid+1;//ƫС��������
        else r = mid-1;
    }
    return ans;
}
ll gcd(ll a,ll b) {//��С������
    return a%b==0?b:gcd(b,a%b);
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        ll n;cin>>n;
        ll val = cal(n);//��������
        ll rest = n-(1+val)*val/2;//ʣ���ֵ
        if(rest==0) cout<<"1\n";//�պü�����ֻ��Ҫһ��
        else cout<<((val+1)/gcd(val+1,rest))<<"\n";//lcm(val+1,rest)/rest
        //������Ҫ��ֵ�����Ϊ rest �ı������ҿ��Ա� (val+1) ����
        //��Ϊ lcm(val+1,rest)/rest ��������������Ϊgcd����
    }
    return 0;
}
