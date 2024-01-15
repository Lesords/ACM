#include<iostream>
#include<string>
using namespace std;
string change(string s) {
    // write code here
    string ans = "";
    int num = 0;
    for(int i = 0;i < s.size();i++) {
        if(s[i]!='a') ans+=s[i];
        else num++;
    }
    while(num>0) ans+='a',num--;
    return ans;
}
int main() {
	string s;
	cin>>s;
	cout<<change(s);
	return 0;
}
