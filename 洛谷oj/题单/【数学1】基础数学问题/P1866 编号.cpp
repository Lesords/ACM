#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;

//��⣺���ݱ�Ŵ�С����
//Ȼ��ÿ��λ�ÿ���ѡ�Ŀ�����Ϊ����ǰֵ - �Ѿ�ѡ�����������ǰ�������
//����λ�����ȡģ��Ϊ���

const int MOD = 1000000007;
int a[55];
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>a[i];
    sort(a+1,a+1+n);//��С��������
    ll ans = 1;
    for(int i = 1;i <= n;i++) {
        //��ǰλ�õĿ�����Ϊ��a[i]-i+1
        //ǰ����(i-1)��
        ans = (ans*(a[i]-i+1))%MOD;
    }
    cout<<ans;
    return 0;
}
