#include<iostream>//ac ��������
using namespace std;
int main() {
    int m,one,two,now;
    cin>>m;
    one = two = 1;//��һ�������ڶ���������������
    for(int i = 3;;i++) {
        now = (one+two)%m;//��ǰ��Ϊǰ������ӣ�ȡģ��
        if(two%m==0&&now%m==1) {//ǰ0��1
            cout<<i-1<<endl;//�жϵ���ǰһ��λ��
            return 0;
        }
        one = two;two = now;//��������
    }
}
