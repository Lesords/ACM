#include<iostream>//ac
#include<string>
#include<algorithm>
using namespace std;
int solve(string a) {//�ַ���ת��Ӧ��ֵ
    int ans_a = 0;
    for(int i = 0;i < (int)a.size();i++) {
        int tmp = a[i]-'0';
        ans_a = ans_a*10+tmp;
    }
    return ans_a;
}
bool check(string tmp) {//�ж��ַ������Ƿ��зǷ��ַ�
    for(int i = 0;i < (int) tmp.size();i++) {
        if(tmp[i]>='0'&&tmp[i]<='9') continue;
        return 1;
    }
    int num = solve(tmp);//��6������������0������
    if(num>1000||num==0) return 1;//���ܳ���1000��Ҳ����Ϊ0������
    return 0;
}
int main() {
    string a,b,tmp;
    int flag = 0,two = 0;
    cin>>a>>b;
    while(cin>>tmp) flag = two = 1;//������Ķ�����b��
    if(check(a)) cout<<"? + ",flag = 1;
    else cout<<a<<" + ";
    if(check(b)||two) cout<<"? = ",flag = 1;//�������Ҳ��Ҫ�жϣ�����
    else cout<<b<<" = ";
    if(flag) cout<<"?";
    else cout<<solve(a)+solve(b);
    return 0;
}
