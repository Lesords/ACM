#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;

//��⣺���1-n��ǰ׺��
//����ֻ����һ�Σ�����ֻ��Ҫ��һ������k������ͼ���
//Ȼ���� ǰ׺�� - ����� ��Ϊ���

const int MAXN = 1e6+5;
ll pre[MAXN],a[MAXN];
int main() {
    int n,k;
    cin>>n>>k;
    for(int i = 2;i <= n;i++) cin>>a[i],pre[i] = pre[i-1]+a[i];
    if(1+k>=n) {//һ��ֱ�������յ�
        cout<<"0\n";return 0;
    }
    ll maxx = 0;//��һ�����ʼ��Ϊ0
    for(int i = 1;i + k <= n;i++) {
        maxx = max(maxx,pre[i+k]-pre[i]);//k������
    }
    cout<<pre[n]-maxx<<endl;
    return 0;
}
