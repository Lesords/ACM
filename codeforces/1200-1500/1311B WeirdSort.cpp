#include<iostream>//ac
#include<cstring>
#include<algorithm>
using namespace std;

//��⣺������п����ƶ���λ�ã�Ȼ�����б�Ƕ�����
//����ж������Ƿ�Ϊ���򼴿�

int a[105],p[105];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,m,flag = 0;
        cin>>n>>m;
        memset(p,0,sizeof(p));//��ʼ��λ��
        for(int i = 1;i <= n;i++) cin>>a[i];
        for(int i = 1;i <= m;i++) {
            int pos;
            cin>>pos;
            p[pos] = 1;//��ǿ�ת�Ƶ�λ��
        }
        for(int i = 1;i <= n;i++) {
            if(p[i]!=1) continue;//���������ƶ���λ��
            int j = i+1;//iΪ���
            while(j<=n&&p[j]) j++;//jΪ����ת�Ƶ�λ��
            sort(a+i,a+j+1);//ת�ư�����һλ������+1������
        }
        for(int i = 2;i <= n;i++) {
            if(a[i]<a[i-1]) {//���������
                flag = 1;break;
            }
        }
        if(flag) cout<<"NO\n";
        else cout<<"YES\n";
    }
    return 0;
}
