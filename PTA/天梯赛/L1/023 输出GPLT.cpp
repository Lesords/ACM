#include<iostream>//ac
#include<string>
#include<cctype>
#include<algorithm>
using namespace std;

//ע�⣺�ַ������Ըı�˳�����Ը���num�����������

string s;
int len,num[5],pos,sum;
char ord[5] = {'G','P','L','T'};
int main() {
    cin>>s;
    len = s.size();
    for(int i = 0;i < len;i++) {
        for(int j = 0;j < 4;j++) {
            if(toupper(s[i])==ord[j]) {
                sum++;//ͳ�ƶ�Ӧ�ַ����������Լ��ܵ�����
                num[j]++;break;
            }
        }
    }
    while(num[pos]==0) pos = (pos+1)%4;//��һ���ַ�����ҲΪ�գ�����
    for(int i = 1;i <= sum;i++) {//�����sum���ַ�
        cout<<ord[pos];
        num[pos]--;//��Ӧ�ַ���--
        pos = (pos+1)%4;//�����λ
        //���һλ��������һλ������
        while(i!=sum&&num[pos]==0) pos = (pos+1)%4;//�ҵ���һ���ַ�������Ϊ0���ַ�
    }
    return 0;
}
