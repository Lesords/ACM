#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;

//��⣺��λ����Сֵ*���ֵ�������СֵΪ0��������ֵ��Ϊ����
//������Сֵ����ܻ�Ϊ0������ֱ����Ϳ�����

ll solve(ll val) {//������Сֵ�����ֵ�ĳ˻�
    int minn = 11, maxx = 0;
    while(val) {
        int tmp = val%10;
        minn = min(minn,tmp);
        maxx = max(maxx,tmp);
        val /= 10;
    }
    return minn*maxx;
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        ll a,k;
        cin>>a>>k;
        while(--k) {//�ҵ�k��
            ll add = solve(a);//���ӵ�ֵ
            if(add==0) break;//��Ϊ0�����������
            a += add;
        }
        cout<<a<<"\n";
    }
    return 0;
}
