#include<iostream>//ac
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

//��⣺����ʼ���죬a��ǰֵ�����b�������Ĵ�ֵȫ��b

const int MAXN = 5e4+5;
char s[MAXN], a[MAXN], b[MAXN];//��aֵ��bֵ��С������
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,mark = 0;//mark��ǵ�һ�������Ƿ���ֽϴ�ֵ
        cin>>n;
        for(int i = 1;i <= n;i++) {
            cin>>s[i];
            if(s[i]=='0') a[i] = b[i] = '0';//0ֻ��һ�ֿ���
            else if(s[i]=='2') {//��Ϊ 1+1 �� 2+0
                if(mark==0) a[i] = b[i] = '1';//����ֵһ����ʱ����
                else a[i] = '0', b[i] = '2';//����ϴ�ֵ��b
            }
            else {
                if(mark==0) a[i] = '1', b[i] = '0';//a���ȸ���ֵ
                else a[i] = '0', b[i] = '1';//���򶼸�b
                mark = 1;
            }
        }
        for(int i = 1;i <= n;i++) cout<<a[i];
        cout<<"\n";
        for(int i = 1;i <= n;i++) cout<<b[i];
        cout<<"\n";
    }
    return 0;
}
