#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;

//��⣺���� f[i] = f[i-1]+f[i+1] ���Լ����ÿ6����ѭ��
//���Կ����ȼ�������������Ȼ��ȡģ
//С���ɣ����������������Ϊ��0�������ʿ�ֱ��ȡģ6
//����MODֻ��1e9+7��������Сֵ����Ϊ -2e9 ������ȡģ��Ҫ����MOD��

const int MOD = 1e9+7;
ll a[8];
int main() {
    ll x,y,n;
    cin>>x>>y>>n;
    a[1] = x;//�ȼ���6����
    a[2] = y;
    a[3] = y-x;
    a[4] = -x;
    a[5] = -y;
    a[0] = -y+x;//���������Ƶ���������ʿ�ֱ��ȡģ6
    //ȡģ��Ҫ����MOD������
    cout<<(a[n%6]+MOD+MOD)%MOD<<"\n";
    return 0;
}
