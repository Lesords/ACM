#include<iostream>//ac
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
const int MAXN = 1e3+5;

//��⣺ֱ�ӱ�ͳ��6�����������������

string s;
int main() {
    getline(cin,s);//����һ��
    int cnt = 0,len = s.size();
    for(int i = 0;i < len;i++) {
        if(i==len-1||s[i]!='6') {//���һ���ַ�����Ϊ6ʱ
            if(i==len-1&&s[i]=='6') cnt++;//�������һ���ַ�
            if(cnt>9) {
                cout<<"27";
                if(s[i]!='6') cout<<s[i];//��ǰ��Ϊ6����Ҫ���
            }
            else if(cnt>3) {
                cout<<"9";
                if(s[i]!='6') cout<<s[i];//��ǰ��Ϊ6����Ҫ���
            }
            else {
                //������е�6
                for(int i = 1;i <= cnt;i++) cout<<'6';
                cout<<s[i];
            }
            cnt = 0;//cnt����
        }
        else ++cnt;//�ۼ�
    }
    return 0;
}
