#include<iostream>//ac
#include<algorithm>
using namespace std;

//��⣺������
//�̳��������������⴦����������
//������Ϊ������������������̽�λ
//����ģ��Ϊ�������� ���� - ģ�� ��Ϊ����
//�� ���� -= ģ������++
//֤����(��+1-1)*ģ��+���� = (��+1)*ģ�� + (���� - ģ��) = ������

char s[30] = {'0','1','2','3','4','5','6','7','8','9','A',
'B','C','D','E','F','G','H','I','K'};//��¼��Ӧֵ���ַ�
int n,r;
string solve() {
    string ans = "";
    while(n) {
        int tmp = n%r;//ȡ����
        n /= r;//ȡ��
        if(tmp<0) tmp -= r,n++;//���и���
        ans += s[tmp];//��Ӷ�Ӧ�ַ�
    }
    reverse(ans.begin(),ans.end());//��ת�ַ���
    return ans;
}
int main() {
    cin>>n>>r;
    cout<<n<<"=";
    cout<<solve();
    cout<<"(base"<<r<<")";
    return 0;
}
