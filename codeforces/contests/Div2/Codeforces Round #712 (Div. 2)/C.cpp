#include<iostream>//ac
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<utility>
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;

//��⣺��������ַ�������߻������ұ߳���0�Ļ����϶��޽�
//��Ϊ���������߻���� ')' �ַ������ұ߻���� '(' �ַ��������ֿ϶��޷�ƥ��
//���еľ��Ǽ�¼ 0 �� 1 ���ֵĴ�����Ϊ������϶��޷�ƥ�䣡����
//��ô�������е�0��˵�������ɶ�ƥ�䣨����Ϊ'('��ż��λ')'��
//�������е�1��˵��ǰ��һ��Ϊ '(',����һ��Ϊ ')'

const int MAXN = 1e5+5;
int pos[MAXN];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        string s;
        cin>>n>>s;
        int zero = 0;
        for(int i = 0;i < s.size();i++) {
            zero += s[i]=='0';//ͳ������ֵĴ���
        }
        int one = n-zero;//����1���ֵĴ���
        if(s[0]=='0'||s[n-1]=='0'||zero%2) {//��βΪ0���ߣ���������������1
            cout<<"NO\n";
            continue;
        }
        int tzero = 0,tone =0;//��ǰλ�õ�0��1������
        string ansA = "",ansB = "";//��¼���Ľ��
        for(int i = 0;i < n;i++) {//��������λ��
            if(s[i]=='1') {//��ǰλ��Ϊ1
                tone++;//��������
                if(tone<=one/2) {//ǰ��һ��Ļ�����Ϊ ( �ַ�
                    ansA += '(';
                    ansB += '(';
                }
                else {//����Ϊ ) �ַ�
                    ansA += ')';
                    ansB += ')';
                }
            }
            else {//��ǰλ��Ϊ0�Ļ�
                tzero++;//��������
                if(tzero%2) {//����λ��Ϊ ( �ַ�
                    ansA += '(';
                    ansB += ')';
                }
                else {//ż��λ��Ϊ ) �ַ�
                    ansA += ')';
                    ansB += '(';
                }
            }
        }
        cout<<"YES\n"<<ansA<<"\n"<<ansB<<"\n";
    }
	return 0;
}
/*
������
3
6
100001
8
11000011
10
1110000111
*/
