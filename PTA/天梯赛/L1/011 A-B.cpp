#include<iostream>//ac
#include<string>
#include<set>
using namespace std;
int main() {
    string s,b;
    set<char> hav;//set�д����Ҫɾ�����ַ�
    getline(cin,s);
    getline(cin,b);//�����ַ������ܶ��пո񣡣���
    for(int i = 0;i < (int)b.size();i++) hav.insert(b[i]);
    for(int i = 0;i < (int)s.size();i++) {
        if(hav.count(s[i])) continue;//������Ҫɾ�����ַ�
        cout<<s[i];
    }
    return 0;
}
