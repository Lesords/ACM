#include<iostream>//ac
#include<string>
using namespace std;
//字符串数组存储对应数字的拼音
string s[10] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
int main() {
    string a;
    cin>>a;
    for(int i = 0;i < (int) a.size();i++) {
        if(i!=0) cout<<" ";
        if(a[i]=='-') cout<<"fu";//处理负号！！！
        else cout<<s[a[i]-'0'];
    }
    return 0;
}
