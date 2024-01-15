#include<iostream>
#include<cstdio>
#include<cmath>
#include<stack>
#include<string>
#include<algorithm>//ac
#define ll long long
using namespace std;
stack<char> st;
string s;
int flag;
int main() {
    cin>>s;
    for(int i = 0;i < s.size();i++) {
        if(s[i]=='('||s[i]=='['||s[i]=='{') st.push(s[i]);
        else {
        	if(st.empty()) {
        		cout<<"No"<<endl;
        		return 0;
        	}
            if(s[i]==')') {
                if(st.top()=='(') st.pop();
                else st.push(s[i]);
            }
            else if(s[i]==']') {
                if(st.top()=='[') st.pop();
                else st.push(s[i]);
            }
            else if(s[i]=='}') {
                if(st.top()=='{') st.pop();
                else st.push(s[i]);
            }
        }
    }
    if(st.empty()) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
