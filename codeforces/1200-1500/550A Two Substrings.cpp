#include<iostream>//ac
#include<string>
#include<algorithm>
using namespace std;

//��⣺���������ֻ��BA+AB��AB+BA���
//���Էֱ�Ѱ�������������

int main() {
    string s;
    cin>>s;
    int len = s.size();
    for(int i = 0;i < len;i++) {
        if(s[i]=='A'&&i+1<len&&s[i+1]=='B') {//�ҵ�AB
            for(int j = i+2;j < len;j++) {
                if(s[j]=='B'&&j+1<len&&s[j+1]=='A') {//Ҳ�ҵ�BA
                    cout<<"YES\n";
                    return 0;
                }
            }
        }
    }
    for(int i = 0;i < len;i++) {
        if(s[i]=='B'&&i+1<len&&s[i+1]=='A') {//����BA
            for(int j = i+2;j < len;j++) {
                if(s[j]=='A'&&j+1<len&&s[j+1]=='B') {//����AB
                    cout<<"YES\n";
                    return 0;
                }
            }
        }
    }
    cout<<"NO\n";//��û�ҵ����NO
    return 0;
}
