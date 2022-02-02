#include<iostream>//ac
#include<stack>//Õ»
#include<string>
using namespace std;
int main() {
	string a;
	stack<char> s;
	cin>>a;
	for(int i = 0;i < a.size();i++) {
		if(a[i] == '@') break;//½áÊø·ûºÅ
		if(a[i] == '(') s.push(a[i]);//±£´æ×óÀ¨ºÅ
		else if(a[i] == ')') {
			if(s.size()==0) {//ÈôÕ»ÄÚÃ»ÓÐ×óÀ¨ºÅ
				s.push(a[i]);break;
			}
			else s.pop();//µ¯³öÕ»¶¥µÄ×óÀ¨ºÅ
		}
	}//Õ»ÈôÎª¿Õ£¬ÔòËµÃ÷À¨ºÅÈ«²¿Æ¥Åä³É¹¦
	cout<<(s.size()?"NO":"YES")<<endl;
	return 0;
} 
