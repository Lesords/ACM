#include<iostream>//ac
#include<algorithm>
using namespace std;
const int MAXN = 1e6+6;
int pos[MAXN];//��¼���ӵ������Ѻ�
int main() {
    int n,tmp,cnt = 0;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        cin>>tmp;
        for(int j = 1;j <= tmp;j++) {//��¼��ǰ�ѵ����г���λ��
            pos[++cnt] = i;
        }
    }
    cin>>n;
    for(int i = 1;i <= n;i++) {
        cin>>tmp;
        cout<<pos[tmp]<<"\n";//�����Ӧλ�ü���
    }
    return 0;
}
