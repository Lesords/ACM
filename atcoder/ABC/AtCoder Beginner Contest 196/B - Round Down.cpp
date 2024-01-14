#include<iostream>//ac
#include<string>
#include<algorithm>
using namespace std;
int main() {
    string s,ans = "";
    cin>>s;
    for(int i = 0;i < s.size();i++) {
        if(s[i]=='.') {
            break;
        }
        else ans += s[i];
    }
    cout<<ans;
    return 0;
}
