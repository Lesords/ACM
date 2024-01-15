#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;

//��⣺������Ŀ���ԣ��У���״̬ = ��������ͬ + ����û����ͬ
//������״̬��˵��ÿ�����˶���m��ѡ������Ϊ m^n
//��������û����ͬ��״̬��˵������ߵķ�����m��ѡ��
//�������ķ���ֻ��m-1��ѡ���ٺ���Ļ���ֻ��m-1ѡ��
//���Խ��Ϊ�� m*(m-1)*(n-1)
//��������ͬ��Խ���� = m^n - m*(m-1)*(n-1)
//ע�⣺�������ų�һ�еģ���������һ�еģ����Ƕ�ά��

const int MOD = 100003;
int poww(ll a,ll b) {//a^bֵ
    ll ans = 1;
    while(b) {
        if(b&1) {
            ans = (ans*a)%MOD;//ȡģ
        }
        a = (a*a)%MOD;//ȡģ
        b >>= 1;
    }
    return ans;
}
int main() {
    ll n,m;
    cin>>m>>n;
    ll all = poww(m,n);//��״̬
    ll dif = m*poww((m-1),(n-1))%MOD;//���ڲ�ͬ��״̬���ǵ�ȡģ������
    cout<<(all-dif+MOD)%MOD;//���allȡģ��ֵ��difС�������Ϊ������������+MOD������
    return 0;
}
