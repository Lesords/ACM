#include<iostream>//ac
#include<string>
using namespace std;
//�ַ�������洢��Ӧ���ֵ�ƴ��
string s[10] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
int main() {
    string a;
    cin>>a;
    for(int i = 0;i < (int) a.size();i++) {
        if(i!=0) cout<<" ";
        if(a[i]=='-') cout<<"fu";//�����ţ�����
        else cout<<s[a[i]-'0'];
    }
    return 0;
}
