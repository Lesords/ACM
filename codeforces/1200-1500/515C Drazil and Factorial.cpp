#include<iostream>//ac
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//��⣺�������е����������Ӧת��Ϊֵ�ϴ�ļ�λ��
//Ȼ��������λ���������������

vector<char> v;
bool cmp(char a, char b) {
    return a > b;
}
int main() {
    int n;
    string s;
    cin>>n>>s;
    for(int i = 0;i < s.size();i++) {
        if(s[i]=='1'||s[i]=='0') continue;//����0��1�����ܳ���0��1��
        //2 3 5 7ֻ��ת��Ϊ����
        //���������ȵ�ǰ-1��Ȼ���ټ�����������ֵ������-2����
        if(s[i]=='2'||s[i]=='3'||s[i]=='5'||s[i]=='7') v.push_back(s[i]);
        else if(s[i]=='4') {
            v.push_back('3');
            v.push_back('2');
            v.push_back('2');
        }
        else if(s[i]=='6') {
            v.push_back('5');//���6
            v.push_back('3');//2*3 = 6
        }
        else if(s[i]=='8') {
            v.push_back('7');//���8
            v.push_back('2');//2*2*2 = 8
            v.push_back('2');
            v.push_back('2');
        }
        else if(s[i]=='9') {//8���У����԰���7������
            v.push_back('7');//��8*9
            v.push_back('3');//2*2*2 * 3*3
            v.push_back('3');
            v.push_back('2');
        }
    }
    sort(v.begin(),v.end(),cmp);//�����������
    for(int i = 0;i < v.size();i++) cout<<v[i];
    return 0;
}
