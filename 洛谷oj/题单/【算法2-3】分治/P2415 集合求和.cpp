#include<iostream>//ac
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;

//��⣺����һ����СΪn�ļ�����˵������2^n���Ӽ�
//����ÿ��Ԫ�ض�������ѡ��ѡ�Ͳ�ѡ����n��Ԫ�أ���Ϊ2^n���Ӽ�
//��ô������Щ�Ӽ���˵��ÿ��Ԫ��ѡ�Ͳ�ѡ��ռ1/2
//��ô���������Ӽ��ͣ�Ȼ�� ����2^n �� ��2

int a[50],cnt;
ll ans;
int main() {
    int tmp;
    while(cin>>tmp) {
        a[++cnt] = tmp;
        ans += tmp;
    }
    //��Ϊlonglong��double�������ʱ��ת��Ϊdouble����
    //������Ҫ��ʾת����longlong����
    cout<<(ll)(ans*pow(2,cnt)/2);
    return 0;
}
