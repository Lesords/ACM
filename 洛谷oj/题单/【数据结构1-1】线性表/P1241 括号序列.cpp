#include<iostream>//ac
#include<string>
#include<stack>
using namespace std;
int book[105];//标记对应位置是否需要补全，1为需要补全
int main() {
	stack<int> sta;//保存字符的索引
	string s;
	cin>>s;
	for(int i = 0;i < s.size();i++) {
		if(s[i]==')'||s[i]==']') {//对于右括号
			if(sta.empty()) {//没有对应的左括号
				book[i] = 1;continue;//需补全，跳过
			}
			//栈顶符号与当前符号可以匹配时，弹出栈顶符号
			if(s[i]==')'&&s[sta.top()]=='(') sta.pop();
			else if(s[i]==']'&&s[sta.top()]=='[') sta.pop();
			else book[i] = 1;//否则需要补全
		}
		else sta.push(i);//左括号则入栈
	}
	while(!sta.empty()) {//若有剩余的左括号
		book[sta.top()] = 1;//需补全，并弹出栈顶符号
		sta.pop();
	}
	for(int i = 0;i < s.size();i++) {
		if(!book[i]) cout<<s[i];//0为不需要补全
		else if(s[i]=='('||s[i]==')') cout<<"()";
		else cout<<"[]";
	}
	return 0;
}
