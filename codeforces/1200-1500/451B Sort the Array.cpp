#include<iostream>//ac
#include<algorithm>
using namespace std;

//��⣺�ֽ�ԭ��������һ�飬Ȼ����������������ԭ����Ա�
//�ҳ� ��һ�� ֵ��һ����λ�ú� ���һ�� ֵ��һ����λ��
//��λ��ֵΪ0����˵����������ѡ������һ��λ�ý�������
//������Ҫ����������䣬�ж�������ֵ�Ƿ�һ������һ������

const int MAXN = 1e5+5;
int a[MAXN], b[MAXN];
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>a[i],b[i] = a[i];
    sort(a+1,a+n+1);//����
    int pos1 = 0,pos2 = 0;//�Ҹ���������λ��
    for(int i = 1;i <= n;i++) {//��������
        if(a[i]!=b[i]) {
            pos1 = i;break;
        }
    }
    for(int i = n;i >= 1;i--) {//���ҵ�����
        if(a[i]!=b[i]) {
            pos2 = i;break;
        }
    }
    if(pos1==0) {//��Ϊ0��Ϊ����
        cout<<"yes\n1 1\n";
        return 0;
    }
    for(int i = pos1,j = pos2;i <= pos2;i++,j--) {//�����������
        if(a[i]!=b[j]) {//��ֵ��ͬ����
            cout<<"no\n";
            return 0;
        }
    }
    cout<<"yes\n"<<pos1<<" "<<pos2<<"\n";
    return 0;
}
