#include<iostream>//ac
#include<set>
#include<string>
#include<algorithm>
#define ull unsigned long long
using namespace std;

//��⣺�����ַ�����Ӧ�Ĺ�ϣֵ��Ȼ�����set��ȥ�ؼ���

const int MOD = 100000007;//ģ��
const int BIT = 131;//������
set<int> st;//ȥ�أ��ж��ַ�������
ull getN(char ch) {//����Ӧ�ַ�һ��ֵ
    if(ch>='0'&&ch<='9') return ch-'0';
    if(ch>='a'&&ch<='z') return ch-'a'+10;
    return ch-'A'+50;
}
ull Hash(string tmp) {//�����ϣֵ
    int len = tmp.size();
    ull bit = 1, ans = 0;
    for(int i = len-1;i >= 0;i--) {//�ӵ�λ����λ��ʼ����
        ans += getN(tmp[i])*bit;
        bit *= BIT;//��ǰλ�õĽ���ֵ
    }
    return ans;//���ع�ϣֵ
}
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        string tmp;
        cin>>tmp;
        st.insert(Hash(tmp));
    }
    cout<<st.size();//ͳ��st������Ϊ��
    return 0;
}
