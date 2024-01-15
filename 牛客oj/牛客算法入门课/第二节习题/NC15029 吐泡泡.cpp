#include<iostream>//ac
#include<string>
#include<stack>
using namespace std;
int main() {
	string s;
	while(getline(cin,s)) {//多组输入
		string ans = "";//初始化为空格
		stack<char> sta;
		for(int i = 0;i < s.size();i++) {
			if(sta.empty()) sta.push(s[i]);//栈为空
			else {
				if(sta.top()==s[i]) {//两个相等
					sta.pop();
					if(s[i]=='o') {//小的需再次判断栈顶
						//栈有符号，且为 'O' 时弹出栈顶
						//否则输入 'O'
						if(sta.size()&&sta.top()=='O') sta.pop();
						else sta.push('O');
					}//大的直接消失了
				}
				else sta.push(s[i]);
			}
		}
		while(!sta.empty()) {
			//先出的在最右边
			ans = sta.top() + ans;
			sta.pop();
		}
		cout<<ans<<'\n';//回车符！！！
	}
	return 0;
}
