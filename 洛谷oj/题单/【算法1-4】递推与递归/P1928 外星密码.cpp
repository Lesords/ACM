#include<iostream>//ac
#include<cstring>
#include<stack>
#include<cctype>
#include<string>
#include<algorithm>
using namespace std;

//��⣺����ջ�ȼ���ÿ��������ƥ���������λ��
//Ȼ��ʼ���������ַ��������Ϊ�ַ���ֱ�����
//���Ϊ���ţ��ȼ������ź�������ִ�С
//Ȼ��ݹ���������ڵ��ַ���������ֱ��ѭ����Ӽ���

const int MAXN = 2e4+5;
char s[MAXN];
int len,pos[MAXN];//pos��¼������ƥ���������λ��
string solve(int l,int r) {//����[l,r]������ַ���
    string ans = "";//��ʼ��Ϊ��
    for(int i = l;i <= r;i++) {
        if(isalpha(s[i])) {                     //Ϊ�ַ�ֱ�����
            ans += s[i];
        }
        else {
            int cnt = 0,now = i;                //cntΪ������nowΪ��ǰ�����λ��
            while(isdigit(s[now+1])) {          //����һλΪ����
                cnt = cnt*10 + (s[++now]-'0');  //��������
            }
            string tmp = "";                    //�洢�����ڵ��ַ�
            tmp = solve(now+1,pos[i]-1);        //���������ڵ��ַ����ǵ��޸����䷶Χ
                                                //nowΪ���ֵ�λ�ã�pos[i]Ϊ�����ŵ�λ��
            while(cnt--) {                      //ѭ�����cnt��tmp
                ans += tmp;
            }
            i = pos[i];                         //�ƶ�i��λ��
        }
    }
    return ans;
}
int main() {
    cin>>s+1;
    len = strlen(s+1);
    stack<int> sta;
    for(int i = 1;i <= len;i++) {               //�����ַ����ڶ�Ӧ������ƥ���������λ��
        if(s[i]=='[') sta.push(i);              //�����ţ�ֱ�ӽ�λ�÷���ջ��
        else if(s[i]==']') {                    //���������ţ�ֱ�ӽ�ջ����������ƥ�䵽��ǰλ��
            pos[sta.top()] = i;
            sta.pop();                          //����ջ��Ԫ��
        }
    }
    cout<<solve(1,len);                         //����[1,len]�ڵ��ַ���
    return 0;
}
