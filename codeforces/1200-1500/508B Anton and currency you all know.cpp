#include<iostream>//ac
#include<string>
#include<algorithm>
using namespace std;

//��⣺���ڸ�������һ��������������ֻ��Ҫ�����Ƿ���ż��λ���ж��Ƿ��н�
//�н�Ļ����ȴӸ�λ����λѰ�ҵ�һ�������һλС��ż�����ҵ��򽻻������
//����������ӵ�λ����λѰ�ҵ�һ�������һλ���ż�����ҵ��򽻻������

int main() {
    string s;
    cin>>s;
    int flag = 0,len = s.size();
    for(int i = 0;i < len;i++) {
        int now = s[i] - '0';
        if(now%2==0) {//�ж��Ƿ���ż��λ
            flag = 1;break;
        }
    }
    if(flag==0) {//û�����޽�
        cout<<"-1";
        return 0;
    }
    int pos = -1,val = s[len-1]-'0';//valΪ���һλ��ֵ(ת��ֵ������
    for(int i = 0;i < len-1;i++) {//�Ӹ�λ����λѰ�ҵ�һ��С��val��ֵ
        int now = s[i] - '0';
        if(now%2==0&&now<val) {
            pos = i;break;
        }
    }
    if(pos==-1) for(int i = len-1;i >= 0;i--) {
        int now = s[i]-'0';
        if(now%2==0&&now>val) {//�ӵ�λ����λѰ�ҵ�һ������val��ֵ
            pos = i;break;
        }
    }
    swap(s[pos], s[len-1]);//�������������
    cout<<s;
    return 0;
}
