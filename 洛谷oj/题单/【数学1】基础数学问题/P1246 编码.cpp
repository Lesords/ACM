#include<iostream>//ac
#include<string>
#include<algorithm>
#define ll long long
using namespace std;

//��⣻���ڸ����ַ�����˵������������ģ����Կ��Ը���λ���Լ�����λ�õ��ַ�
//������֮ǰ���ַ����������Ӷ������ǰ�ַ������������
//����λ��n���ַ�����˵
//֮ǰ���ַ����У�λ��1,2,3������,n-1 ��Ӧ������ΪC(26,i) (��26���ַ�ѡi���������)
//����λ�����ڵ�ǰ�ַ�����˵��
//����ж��ַ������ں�����ַ�������ڵ�ǰ�ַ������к�����ַ�����ѡ�������Ϊ'z'-j��jΪ��ǰ�ַ���

int c(int n,int m) {//n���ַ���ѡm���ַ��������
    int ans = 1;
    for(int i = n-m+1;i <= n;i++) ans *= i;
    for(int i = 1;i <= m;i++) ans /= i;
    return ans;
}
int main() {
    string s;
    cin>>s;
    int len = s.size(),ans = 0;
    for(int i = 1;i < len;i++) {//����������Ϊ������
        if(s[i]<=s[i-1]) {//���ܵ��ڣ�����
            cout<<"0";
            return 0;
        }
    }
    for(int i = 1;i < len;i++) {//�ȼ���С�ڵ�ǰλ�����ַ�������
        ans += c(26,i);
    }
    for(int i = 0;i < len;i++) {//����ַ��ж�
        char tmp = i==0?'a':s[i-1]+1;//�߽磨����һ��λ�õ��ַ���ʼ״̬
        for(char j = tmp;j < s[i];j++) {//���ܵ��ڵ�ǰ�ַ�������
            ans += c('z'-j,len-i-1);//��ʼλ��Ϊ0�����Ժ����������λ����-1
        }
    }
    cout<<ans+1;//���б���һλ
    return 0;
}
