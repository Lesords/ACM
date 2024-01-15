#include<iostream>//ac
#include<string>
#include<algorithm>
using namespace std;

//题解：满足题意的只有BA+AB和AB+BA组合
//所以分别寻找两种情况即可

int main() {
    string s;
    cin>>s;
    int len = s.size();
    for(int i = 0;i < len;i++) {
        if(s[i]=='A'&&i+1<len&&s[i+1]=='B') {//找到AB
            for(int j = i+2;j < len;j++) {
                if(s[j]=='B'&&j+1<len&&s[j+1]=='A') {//也找到BA
                    cout<<"YES\n";
                    return 0;
                }
            }
        }
    }
    for(int i = 0;i < len;i++) {
        if(s[i]=='B'&&i+1<len&&s[i+1]=='A') {//先找BA
            for(int j = i+2;j < len;j++) {
                if(s[j]=='A'&&j+1<len&&s[j+1]=='B') {//再找AB
                    cout<<"YES\n";
                    return 0;
                }
            }
        }
    }
    cout<<"NO\n";//都没找到输出NO
    return 0;
}
