#include<iostream>//ac
#include<string>
#include<algorithm>
using namespace std;

//��⣺��ͳһתΪʮ���ƣ�Ȼ����ת��ָ��������

char v[20] = {'0','1','2','3','4','5','6','7','8','9','A','B',
'C','D','E','F'};//�洢��Ӧֵ���ַ�
int get_n(char c) {//��ȡ��ǰ�ַ���Ӧ��ֵ
    if(c>='0'&&c<='9') return c-'0';
    return c-'A'+10;
}
int solve(string s,int bit) {//�ַ���Ϊs����ǰ����Ϊbit
    int len = s.size()-1,val = 1,sum = 0;//sum�洢�����valΪ��Ӧ����λ��ֵ
    for(int i = len;i >= 0;i--) {//�ӵ�λ����λ
        int num = get_n(s[i]);//��ǰλ��ֵ
        sum += num*val;//���½��
        val *= bit;//���¶�Ӧ����λ��ֵ
    }
    return sum;//���ؽ��
}
string change(int val,int bit) {//valתΪbitλ���ַ���
    string ans = "";//�ӵ�λ���λ�洢��Ȼ���ٷ�ת�ַ�������
    while(val) {
        ans += v[val%bit];//��Ӷ�Ӧֵ���ַ�
        val /= bit;
    }
    reverse(ans.begin(),ans.end());//��ת�ַ���
    return ans;
}
int main() {
    string s;
    int n,m;
    cin>>n>>s>>m;
    int val = solve(s,n);
    cout<<change(val,m);
    return 0;
}
