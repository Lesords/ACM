#include<iostream>//ac
#include<cmath>
#include<algorithm>
using namespace std;

//��⣺������
//������Ϊ1ʱ�����ֱذ�
//������Ϊ2ʱ�����ֱ�ʤ��ɾ��һ��1��ʣ��1��
//������Ϊ����ʱ�����ֱ�ʤ��ֱ�ӳ��Ա���ʣ��1��
//������Ϊż��ʱ�����������������û�������ӵ�ż�����ֱذܣ�������
// ��Ϊ��ʱ��ֻ��-1�Ĳ��������¶�����һ����ʤ������
//�����������Ӳ��ҳ��Ľ����Ϊ2�����ֱ�ʤ����ȥ���������ӣ�ʣ��һ���ذܵ�ż����
//���������ֱذܣ���2����ˣ�û��������Ҳ���ˣ�

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        if(n==1) cout<<"FastestFinger\n";
        else if(n==2||n%2) cout<<"Ashishgup\n";
        else {
            int flag = 0;
            for(int i = 2;i <= (int) sqrt(n);i++) {//Ѱ�������ӣ�������һ����Ϊ2
                if(n%i) continue;//�����������ӵ���
                if(i%2&&(n/i)!=2) {//��ǰΪ������������һ����Ϊ2
                    flag = 1;break;
                }
                if((n/i)%2&&i!=2) {//��һ��Ϊ��������ǰ��Ϊ2
                    flag = 1;break;
                }
            }
            if(flag) cout<<"Ashishgup\n";//�ҵ�������ʤ��
            else cout<<"FastestFinger\n";
        }
    }
    return 0;
}
