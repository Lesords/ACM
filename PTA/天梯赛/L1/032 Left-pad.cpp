#include<iostream>//ac
#include<string>
using namespace std;
string s;
int main() {
    int n;
    char op;
    cin>>n>>op;
    getchar();//����ĩβ�س���
    getline(cin,s);
    if(s.size()>n) {//�ַ���������ֱ�ӽض�
        for(int i = s.size()-n;i < (int)s.size();i++) cout<<s[i];
    }
    else {//�����Ȳ�ȫ�������
        for(int i = 1;i <= n-s.size();i++) cout<<op;
        cout<<s<<endl;
    }
    return 0;
}
