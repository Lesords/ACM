#include<iostream>//ac
#include<string>
#include<algorithm>
using namespace std;

//��⣺����ַ����к���Z�ַ�ʹ��Z֮�����е��ַ�����ΪZ����������������
//������ֱ���жϼ���

const int MAXN = 1e6+6;
char ansA[MAXN],ansB[MAXN];
bool judge(string tmp) {//�ж�Z�ַ������Ƿ�ΪZ
    int flag = 0;
    for(int i = 0;i < tmp.size();i++) {
        if(tmp[i]=='Z') flag = 1;
        else if(flag&&tmp[i]!='Z') return true;//��ΪZ���޽�
    }
    return false;
}
int main() {
    string s;
    cin>>s;
    if(judge(s)) {//�޽�
        cout<<"-1";
        return 0;
    }
    for(int i = 0;i <= s.size();i++) {
        if(s[i]=='X') ansA[i] = '1',ansB[i] = '0';//�ϴ��ȡ1����С��Ϊ0
        else if(s[i]=='Y') ansA[i] = '0',ansB[i] = '1';
        else ansA[i] = ansB[i] = '0';//���Ϊ0
    }
    for(int i = 0;i < s.size();i++) cout<<ansA[i];
    cout<<"\n";
    for(int i = 0;i < s.size();i++) cout<<ansB[i];
    return 0;
}
