#include<iostream>//ac
#include<algorithm>
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;

//��⣺����ѡ��ֻ��ɾ��ͷ����β��
//���Կ��Լ���ǰ׺�� �� ��׺���Ƿ���ָ�����0��ɾ����ǰ׺���׺����ڵ����ܺͣ�
//���У���ΪNO������ΪYES

const int MAXN = 1e5+5;
ll a[MAXN];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,flag = 0;
        ll sum = 0;
        cin>>n;
        for(int i = 1;i <= n;i++) cin>>a[i];
        for(int i = 1;i < n;i++) {//����ǰ׺�����������һλ��
            sum += a[i];
            if(sum<=0) {//���ַ�����
                flag = 1;break;
            }
        }
        sum = 0;
        for(int i = n;i > 1;i--) {//�����׺����������һλ��
            sum += a[i];
            if(sum<=0) {//���ַ�����
                flag = 1;break;
            }
        }
        if(flag) cout<<"NO\n";//NOΪ������
        else cout<<"YES\n";
    }
    return 0;
}
