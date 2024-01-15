#include<iostream>//ac
#include<string>
#include<stack>
#include<algorithm>
using namespace std;
string tmp,a[10004];
string change(string tmp) {//去除 < 操作的字符串
	stack<char> sta;//用栈保存剩余字符
	for(int i = 0;i < tmp.size();i++) {
		if(sta.empty()) {//栈为空时不为<就保存
			if(tmp[i]!='<') sta.push(tmp[i]);
		}
		else if(tmp[i]=='<') sta.pop();//弹出栈顶
		else sta.push(tmp[i]);//入栈
	}
	tmp = "";
	while(!sta.empty()) {//遍历剩余字符
		tmp = sta.top() + tmp;//倒着保存，top需放在左边
		sta.pop();
	}
	return tmp;
}
int main() {
	int cnt = 1,ans = 0,cos;
	while(getline(cin,tmp)) {	//整行输入
		if(tmp=="EOF") break;	//EOF停止
		tmp = change(tmp);		//修改tmp中的<
		a[cnt++] = tmp;			//保存对应字符串
	}
	int num = 1;
	while(getline(cin,tmp)) {	//整行输入
		if(tmp=="EOF") break;	//EOF结束
		if(num>=cnt) continue;	//超过范文行
		tmp = change(tmp);		//修改tmp中的<
		//取范文和当前tmp的较短值
		int siz = min(tmp.size(),a[num].size())-1;
		for(int i = 0;i <= siz;i++) {//遍历判断是否有相同字符
			if(a[num][i]==tmp[i]) ans++;
		}
		num++;//移动范文
	}
	cin>>cos;//输入cos秒
	cout<<int(ans*60.0/cos)<<endl;//求 个/分钟
	return 0;
}
