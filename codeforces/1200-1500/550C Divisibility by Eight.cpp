#include<iostream>//ac
#include<string>
#include<algorithm>
using namespace std;

//��⣺�ж�һ�����Ƿ�Ϊ8�ı���ֻ��Ҫ�ж������λ�Ƿ�Ϊ8�ı�������
//��Ӧһλ����ֻ��Ҫ0����8
//��λ����λ�ֱ�ʼ���죬Ȼ���ж��Ƿ�Ϊ8�ı�������

int to_n(char ch) {//�ַ�ת����
    return ch - '0';
}
int main() {
    string s;
    cin>>s;
    int len = s.size(),flag = 0;
    for(int i = 0;i < len;i++) {
        if(s[i]=='0') {//����0
            flag = 1;break;
        }
        if(s[i]=='8') {//����8
            flag = 8;break;
        }
    }
    if(flag==1) {//������0
        cout<<"YES\n0\n";
        return 0;
    }
    if(flag==8) {//������8
        cout<<"YES\n8\n";
        return 0;
    }
    for(int i = 0;i < len;i++) {
        for(int j = i+1;j < len;j++) {//������λ��
            int num = to_n(s[i])*10+to_n(s[j]);
            if(num%8==0) {//Ϊ8�ı������ɽ���
                flag = 1;
                cout<<"YES\n"<<num<<"\n";
                return 0;
            }
        }
    }
    for(int i = 0;i < len;i++) {//������λ��
        if(flag) break;
        for(int j = i+1;j < len;j++) {
            if(flag) break;
            for(int k = j+1;k < len;k++) {
                int num = to_n(s[i])*100+to_n(s[j])*10+to_n(s[k]);
                if(num%8==0) {//Ϊ8�ı������ɽ���
                    flag = 1;
                    cout<<"YES\n";
                    cout<<num<<"\n";
                    break;
                }
            }
        }
    }
    if(flag==0) cout<<"NO\n";
    return 0;
}
