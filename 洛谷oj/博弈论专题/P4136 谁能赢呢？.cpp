#include<iostream>//ac
#include<algorithm>
using namespace std;

//��⣺������Ϊ���Ų����߲�����ô���տ϶���Ҫ�������еĸ��ӵ�
//�����n��˵����ʣ�� n*n-1 �����ӿ����ߵ�
//����������˵��ʣ������������Ϊ��ʤ
//���� n*n-1 Ϊ�������� n*n Ϊż��
//����n*n��n����ż��һ�£�����ֱ���ж�n����ż�Լ���

int main() {
    int n;
    while(cin>>n&&n) {//��0��������
        if(n&1) cout<<"Bob\n";//��Ϊ����������ż�������ӣ������ʤ��
        else cout<<"Alice\n";
    }
    return 0;
}
