#include<iostream>//ac
#include<string>
#include<algorithm>
using namespace std;

//题解：若原串为非回文，则最长非回文子字符串即为原串长度
//若原串为回文，则最长非回文子字符串为原串长度-1
//需要特判字符串中每个字符都相等的情况！！！

bool check(string val) {//判断是否为回文串
    string rval = "";
    for(int i = val.size()-1;i >= 0;i--) rval+=val[i];
    return val==rval;
}
bool all_same(string val) {//特判所有字符都相等的情况
    for(int i = 1;i < val.size();i++) {
        if(val[i]!=val[0]) return false;
    }
    return true;
}
int main() {
    string s;
    cin>>s;
    if(all_same(s)) {//所有字符都相等，则最长非回文字符串为0
        cout<<"0\n";return 0;
    }
    if(check(s)) cout<<s.size()-1<<"\n";//为回文串，需减1
    else cout<<s.size()<<"\n";//否则即为本身
    return 0;
}
