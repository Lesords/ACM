#include<iostream>//ac
#include<set>
#include<string>
#include<algorithm>
using namespace std;
int y,n,year;
string to_str(int n) {//������תΪ�ַ�����������4����ǰ����
    string ans = "";
    while(n) {
        char op = n%10 + '0';
        ans = op + ans;
        n /= 10;
    }
    while(ans.size()<4) ans = '0'+ans;
    return ans;
}
int check(int n) {
    string tmp = to_str(n);
    set<char> st;
    for(int i = 0;i < (int)tmp.size();i++) st.insert(tmp[i]);//ͳ���м�������
    return st.size();//��������������
}
int main() {
    cin>>y>>n;
    for(int i = y;;i++) {
        if(check(i)==n) {//��������������ʱ
            cout<<year<<" "<<to_str(i)<<"\n";
            return 0;
        }
        year++;//��¼����
    }
    return 0;
}
