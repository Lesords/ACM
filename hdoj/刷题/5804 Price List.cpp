#include<iostream>//ac
#include<string>
#include<algorithm>
#define ll long long
using namespace std;

//���⣺ÿ����������̵�Ĳ�Ʒ���������㲻�ܶ���
//��⣺�ۼ����е��̵��ܺͣ��жϵ�ǰֵ�Ƿ񳬹��ܺͼ���
//���������1���������0
//ע�⣺���˵�������ΧΪ1e18��������ll������

const int MAXN = 1e5+5;
ll a[MAXN];
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n,m;
        scanf("%d %d", &n, &m);
        ll tmp,sum = 0;//sum�ۼӺ�
        for(int i = 1;i <= n;i++) scanf("%lld", &tmp),sum+=tmp;
        for(int i = 1;i <= m;i++) scanf("%lld", &a[i]);//ע��ll
        for(int i = 1;i <= m;i++) {
            printf("%d", a[i]>sum);//�ж��Ƿ�����ܺͼ���
        }
        puts("");
    }
    return 0;
}
