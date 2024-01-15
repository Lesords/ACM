#include<iostream>//ac
#include<cstdio>
#include<stack>
using namespace std;

//题解：判断当前的栈是否可以输出最大值
//可以则输出，否则入栈
//最后判断栈是否有剩余数值，逐个输出即可

int main() {
	int n,tmp,num;
	stack<int> s;
	scanf("%d",&n);
	num = n;//用来记录当前的最大值
	for(int i = 1;i <= n;i++) {
		scanf("%d",&tmp);
		if(tmp==num) {//为当前最大值
			if(num!=n) cout<<' ';//第一个数无需空格
			cout<<tmp;//输出
			num--;//修改当前最大值
		}
		else s.push(tmp);//入栈
	}
	while(!s.empty()) {
		if(s.top()!=n) cout<<' ';//第一个数无需空格
		cout<<s.top();//按顺序输出即可
		s.pop();
	}
	return 0;
}
