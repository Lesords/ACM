#include<iostream>//ac
#include<string>
#include<algorithm>
using namespace std;

//��⣺������������֪��ǰ�����ƶ�����ѡ���м�� o* �Ƶ��ո�λ
//Ȼ���ٰѿո�λ�Ƶ����ҵ� ** λ��
//�������������˵��ֱ�Ӵ���������o*��ϣ���Ҫ��һ��o*������
//��Ҫע����ǣ������ӵ� o* ��Ҫ��һ�飬��Ϊ�������Ƕ��һ�� o* ��

/*
������
���룺7
�����
ooooooo*******--
oooooo--******o*
oooooo******--o*
ooooo--*****o*o*
ooooo*****--o*o*
oooo--****o*o*o*
oooo****--o*o*o*
ooo--***o*o*o*o*

ooo*o**--*o*o*o*  ��ooo***--o*o*o*o*��
o--*o**oo*o*o*o*
o*o*o*--o*o*o*o*
--o*o*o*o*o*o*o*
���з���۲�
*/

string s;
string last[4] = {"ooo*o**--*","o--*o**oo*","o*o*o*--o*",
    "--o*o*o*o*"};//��������4�� o*
int main() {
    int n;
    cin>>n;
    s = string(n,'o')+string(n,'*')+"--";//��ʼ���
    for(int i = 1;i <= n-3;i++) {//����������飬����ֱ��ת��
        cout<<s<<"\n";//δ�ƶ�ǰ
        for(int i = 0;i < s.size();i++) {//���м�� o* ��Ϊ --
            if(s[i]=='o'&&s[i+1]=='*') {
                s[i] = s[i+1] = '-';
                break;
            }
        }
        //���Ե���Ѱ��
        for(int i = s.size()-1;i >= 0;i--) {//��ĩβ�� -- ��Ϊ o*
            if(s[i]=='-'&&s[i-1]=='-') {
                s[i] = '*';
                s[i-1] = 'o';
                break;
            }
        }
        cout<<s<<'\n';//�ƶ�����ַ���
        //�ո��λ���Ƶ��ұ�
        for(int i = 0;i < s.size();i++) {//�м�� -- ��Ϊ **
            if(s[i]=='-'&&s[i+1]=='-') {
                s[i] = s[i+1] = '*';
                break;
            }
        }
        //���Ե���Ѱ��
        for(int i = s.size()-1;i >= 0;i--) {//ĩβ�� **��Ϊ --
            if(s[i]=='*'&&s[i-1]=='*') {
                s[i] = s[i-1] = '-';
                break;
            }
        }
    }
    for(int i = 0;i < 4;i++) {//�������
        s = last[i];
        //��Ҫ���ȥһ������� o*������Ϊ n-3��
        for(int j = 1;j <= n-4;j++) s += "o*";
        cout<<s<<"\n";
    }
    return 0;
}
