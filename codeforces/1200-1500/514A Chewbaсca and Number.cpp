#include<iostream>//ac
#include<string>
#include<algorithm>
using namespace std;
int main() {
    string s;
    cin>>s;
    for(int i = 0;i < s.size();i++) {//ʲô���ֶ�����ѡ������Ҫ�̶�һ�����֣�����
        if(i==0&&s[i]=='9') cout<<s[i];//���е�һλ
        else {
            int val = s[i]-'0';
            //�ж�ת�����ԭ����ֵ�ĸ�С��ѡ���Сֵ�������
            if(9-val<val) cout<<char(9-val+'0');
            else cout<<s[i];
        }
    }
    return 0;
}
