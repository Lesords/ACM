#include<iostream>//ac
#include<cstdio>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;
int main() {
    int n;
    cin>>n;
    getchar();
    while(n--) {
        string s;
        getline(cin,s);
        int num = 0;
        //�ҵ����ź;�ţ�Ȼ���ж�ǰ�����ַ��Ƿ�Ϊ��ong"����
        for(int i = 0;i < (int)s.size();i++) {
            if(s[i]==','||s[i]=='.') {
                string tmp = "";
                for(int j = i-3;j <= i-1;j++) tmp += s[j];
                if(tmp=="ong") num++;
            }
        }
        if(num!=2) cout<<"Skipped\n";//û�ж�Ϊ��ong����������
        else {
            int pos = 0,num = 0;
            for(int i = (int)s.size()-1;i >= 0;i--) {//�����ҵ��������ո��λ��
                if(s[i]==' ') num++;
                if(num==3) {//posΪ�������ո��λ��
                    pos = i;break;
                }
            }//Ȼ��������λ�õ������ַ�������϶�Ӧ�ַ�������
            for(int i = 0;i <= pos;i++) cout<<s[i];
            cout<<"qiao ben zhong.\n";
        }
    }
    return 0;
}
