#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;
const int MAXN = 2e5+5;
int a[MAXN];
ll solve(ll val) {//��ͷ��ʼ��ǰ���������ں���ģ�����ǼӲ��ǳˣ�����
    return val*(val-1)/2;//Ϊ�Ȳ����У���͹�ʽ����
}
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>a[i];
    sort(a+1, a+n+1);
    int num_l = 1, num_r = 1;
    for(int i = 2;i <= n;i++) {//������Сֵ������
        if(a[i]==a[1]) num_l++;
        else break;
    }
    for(int i = n-1;i >= 1;i--) {//�������ֵ������
        if(a[i]==a[n]) num_r++;
        else break;
    }
    if(a[1]==a[n]) {//����ֵ��ͬ�����õȲ���͹�ʽ����
        cout<<"0 "<<solve(num_l)<<"\n";
    }
    else cout<<a[n]-a[1]<<" "<<num_l*1ll*num_r<<"\n";//����ֱ����˼���
    return 0;
}
