#include<iostream>//ac
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;

//��⣺���Լ��*��С������ = ԭ�������ĳ˻� ������
//�����ȼ����������ĳ˻�������ٱ�������˻�����������
//�жϷ����������������Ҫע��ƽ����

ll gcd(ll a,ll b) {//�����Լ��
    return b==0?a:gcd(b,a%b);
}
int main() {
    int a,b;
    cin>>a>>b;
    ll val = a*1ll*b;//�������ĳ˻�
    int n = sqrt(val);
    int ans = 0,vis = 0;//vis�ж��Ƿ���ƽ����
    for(int i = 1;i <= n;i++) {//������������
        //iΪval������
        if(val%i==0&&gcd(i,val/i)==a) {//a�����Լ��������
            ans++;
            if(i*1ll*i==val) vis++;//Ϊƽ����
        }
    }
    cout<<ans*2-vis;//����λ��Ҳ��һ�Σ�������*2���۳���ƽ���������
    return 0;
}
