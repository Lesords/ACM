//003 ��λ��ͳ��
#include<iostream>//ac
#include<string>
using namespace std;
int num[10];
int main() {
    string s;//1000λ����Ҫ���ַ����洢
    cin>>s;
    for(int i = 0;i < s.size();i++) num[s[i]-'0']++;//ͳ������
    for(int i = 0;i <= 9;i++) {
        if(num[i]==0) continue;//����0
        cout<<i<<":"<<num[i]<<"\n";
    }
    return 0;
}
