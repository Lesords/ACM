#include<iostream>//ac
#include<cstring>
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;

//��⣺ֱ�ӱ���һ�飬Ѱ��ÿһ���������߸��������ֵ��Ȼ��ȡ�ͼ���

const int MAXN = 2e5+5;
ll a[MAXN];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        for(int i = 1;i <= n;i++) {
            cin>>a[i];
        }
        ll ans = 0;
        for(int i = 1;i <= n;) {//i��λ����ÿ���жϾ���
            if(a[i]>0) {//������
                ll tmp = 0;//��ʼ��Ϊ0����Ӧ������˵��С��
                for(int j = i;j <= n;j++) {
                    if(a[j]<0) {//��Ϊ��������������޸�i��ֵ
                        i = j;break;
                    }
                    tmp = max(tmp, a[j]);
                    if(j==n) i = j+1;//�������һ����ҲΪ������
                }
                ans += tmp;
            }
            else {//������
                ll tmp = -INF;
                for(int j = i;j <= n;j++) {
                    if(a[j]>0) {//Ϊ��������������޸�i��λ��
                        i = j;break;
                    }
                    tmp = max(tmp, a[j]);
                    if(j==n) i = j+1;//�������һ��λ��
                }
                ans += tmp;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
