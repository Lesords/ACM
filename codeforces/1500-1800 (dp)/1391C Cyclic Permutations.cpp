#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;

//��⣺����n����������һ��λ�ÿ������ӣ���n-1���ߣ��γ�һ����
//��������˵������������һ���߶������γɻ�
//������Ŀ��˵����Ҫ�󻷵���������ô���Լ����ܵ�����-û�л�������
//�����γ�����Ҫô �������� Ҫô �����ݼ� Ҫô ������n�ٵݼ�
//��nΪ��׼������������n-1�����ķ���ѡ�������֣�����Ϊ2^(n-1)

const int MOD = 1e9+7;
ll poww(ll a,ll b) {//�����ݣ���η�
    ll ans = 1;
    while(b) {
        if(b&1) ans = (ans*a)%MOD;
        a = (a*a)%MOD;
        b>>=1;
    }
    return ans;
}
int main() {
    int n;
    ll sum = 1;
    cin>>n;
    for(int i = 1;i <= n;i++) sum = (sum*i)%MOD;//���еĿ�����
    cout<<(sum-poww(2,n-1)+MOD)%MOD;//�۳��������
    return 0;
}
