#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;

//��⣺��С��������Ȼ���Ӧ������תΪ��Ӧ�±�ֵ����
//�������ע��ȡ����ֵ

const int MAXN = 3e5+5;
ll a[MAXN],ans;
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>a[i];
    sort(a+1,a+1+n);//��С��������
    for(int i = 1;i <= n;i++) {//i��Ϊ��ǰĿ����
        ans += llabs(i-a[i]);//ȡ����ֵ
    }
    cout<<ans;
    return 0;
}
