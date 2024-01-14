#include<iostream>//ac
#include<string>
#include<set>
using namespace std;
int main() {
    string s,b;
    set<char> hav;//set中存放需要删除的字符
    getline(cin,s);
    getline(cin,b);//两个字符串可能都有空格！！！
    for(int i = 0;i < (int)b.size();i++) hav.insert(b[i]);
    for(int i = 0;i < (int)s.size();i++) {
        if(hav.count(s[i])) continue;//跳过需要删除的字符
        cout<<s[i];
    }
    return 0;
}
