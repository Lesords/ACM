#include<iostream>//ac
using namespace std;

//��⣺��BW��ϵ���ʽ��������� - �ַ�����

char s[105][105];
int main() {
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) cin>>s[i][j];
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            if(s[i][j]=='-') cout<<s[i][j];//-��ֱ�����-����
            else {
                if((i+j)%2) cout<<"B";//������ż�����ж�������ַ�
                else cout<<"W";
            }
        }
        cout<<"\n";//ÿ�к���Ļس��ַ�
    }
    return 0;
}
