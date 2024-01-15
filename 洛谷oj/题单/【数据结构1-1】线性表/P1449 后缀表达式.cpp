#include<iostream>//ac
#include<stack>
#include<string>
using namespace std;
int main() {
	stack<int> sta;
	string s;
	cin>>s;
	for(int i = 0;i < s.size()-1;i++) {
		int tmp = 0,op1,op2;//tmp为数字
		while(s[i]>='0'&&s[i]<='9') {//为数字类型的时候
			tmp = tmp*10+s[i]-'0';
			i++;
		}
		if(s[i]=='.') sta.push(tmp);//.时导入数字
		else {//运算操作导出头部两个数字
			op1 = sta.top(),sta.pop();
			op2 = sta.top(),sta.pop();
		}//进行对应操作，注意op2与op1的顺序！！！
		if(s[i]=='-') sta.push(op2-op1);
		else if(s[i]=='+') sta.push(op1+op2);
		else if(s[i]=='*') sta.push(op1*op2);
		else if(s[i]=='/') sta.push(op2/op1);
	}
	cout<<sta.top();
	return 0;
}
