#include<iostream>//ac
#include<algorithm>
using namespace std;

//��⣺�����Ӧ������������к���½�������
//Ȼ�������һ���жϿ���ɵ��������
//ע������ȫΪ������ȫΪ�½�

const int MAXN = 105;
int a[MAXN],up[MAXN],down[MAXN];
//up[i]: ��1��i�������������
//down[i]: ��i��n����½�������
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>a[i],up[i]=down[i]=1;//��ʼ����Ϊ1
    //�����������
    for(int i = 2;i <= n;i++) {//��ǰ�����ж�
        for(int j = 1;j < i;j++) if(a[i]>a[j]) {//jǰi��
            up[i] = max(up[i],up[j]+1);//����
        }
    }
    //��½�������
    for(int i = n-1;i >= 1;i--) {//�Ӻ�ǰ�ж�
        for(int j = n;j > i;j--) if(a[i]>a[j]) {//iǰj��
            down[i] = max(down[i],down[j]+1);//����
        }
    }
    int ans = 1;//����Ҫ�Գƣ�����
    for(int i = 1;i <= n;i++) ans = max(ans,up[i]+down[i]-1);//ȡ�������
    cout<<n-ans<<endl;//�����Ϊ��������
    return 0;
}
