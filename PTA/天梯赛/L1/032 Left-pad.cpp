#include<iostream>//ac
#include<string>
using namespace std;
string s;
int main() {
    int n;
    char op;
    cin>>n>>op;
    getchar();//处理末尾回车符
    getline(cin,s);
    if(s.size()>n) {//字符串过长，直接截断
        for(int i = s.size()-n;i < (int)s.size();i++) cout<<s[i];
    }
    else {//否则，先补全，后输出
        for(int i = 1;i <= n-s.size();i++) cout<<op;
        cout<<s<<endl;
    }
    return 0;
}
