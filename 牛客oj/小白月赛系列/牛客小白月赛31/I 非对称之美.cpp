#include<iostream>//ac
#include<string>
#include<algorithm>
using namespace std;

//��⣺��ԭ��Ϊ�ǻ��ģ�����ǻ������ַ�����Ϊԭ������
//��ԭ��Ϊ���ģ�����ǻ������ַ���Ϊԭ������-1
//��Ҫ�����ַ�����ÿ���ַ�����ȵ����������

bool check(string val) {//�ж��Ƿ�Ϊ���Ĵ�
    string rval = "";
    for(int i = val.size()-1;i >= 0;i--) rval+=val[i];
    return val==rval;
}
bool all_same(string val) {//���������ַ�����ȵ����
    for(int i = 1;i < val.size();i++) {
        if(val[i]!=val[0]) return false;
    }
    return true;
}
int main() {
    string s;
    cin>>s;
    if(all_same(s)) {//�����ַ�����ȣ�����ǻ����ַ���Ϊ0
        cout<<"0\n";return 0;
    }
    if(check(s)) cout<<s.size()-1<<"\n";//Ϊ���Ĵ������1
    else cout<<s.size()<<"\n";//����Ϊ����
    return 0;
}
