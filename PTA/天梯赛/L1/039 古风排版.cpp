#include<iostream>//ac
#include<cstring>
#include<cmath>
#include<string>
#include<vector>
using namespace std;
string s;
int main() {
    int n;
    cin>>n;
    getchar();//��ȡ����ĩβ�س���
    getline(cin,s);
    int len = s.size();
    int siz = ceil(len*1.0/n);//�����ܹ��м���
    vector<vector<char> > ans(n,vector<char>(siz,' '));//��ʼ����άvector
    int pos = 0;
    for(int i = siz-1;i >= 0;i--) {//��������
        for(int j = 0;j < n;j++) {//��Ҫ���⴦���ַ���������������
            if(pos>=len) ans[j][i] = ' ';//��������ַ�����С����Ϊ�ո�
            else ans[j][i] = s[pos++];
        }//���һ�в�����Ҫ����ո񣡣���
    }
    for(int i = 0;i < n;i++) {//������
        for(int j = 0;j < siz;j++) cout<<ans[i][j];
        cout<<"\n";
    }
    return 0;
}
