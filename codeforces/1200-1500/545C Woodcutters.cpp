#include<iostream>//ac
#include<algorithm>
using namespace std;

//��⣺̰�ģ������󵹾����󵹣������ҵ������ҵ������򲻶�

const int MAXN = 1e5+5;
int a[MAXN], h[MAXN];
int main() {
    int n,ans = 0;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        cin>>a[i]>>h[i];
    }
    for(int i = 1;i <= n;i++) {
        if(i==1) ans++;//��һ��λ��
        else {
            if(a[i]-h[i]>a[i-1]) ans++;//��������
            else if(i==n||a[i]+h[i]<a[i+1]) {//���һ�����߿������ҵ�
                ans++;
                a[i] += h[i];//���ҵ���Ҫ���µ�ǰ����λ�ã�����
            }
        }
    }
    cout<<ans;
    return 0;
}
