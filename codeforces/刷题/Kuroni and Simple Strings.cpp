#include<iostream>//ac
#include<string>
using namespace std;
int ansa[1005],ansb[1005];
int main() {
	string s;
	cin>>s;
	int l = 0,r = s.size()-1;
	int a = 0,b = 0;
	while(l<=r) {//相同时还需遍历一个位置
		while(l<=r&&s[l]!='(') l++;//找左括号
		while(l<=r&&s[r]!=')') r--;//找右括号
		if(l<=r) {
			ansa[++a] = l+1;//起点为0，需加1
			ansb[++b] = r+1;
			l++,r--;//筛掉之后移动指针！！！
		}
	}
	if(!a||!b) cout<<"0\n";//没有足够的括号
	else {
		cout<<"1\n"<<a+b<<endl;//一次筛掉所有的可匹配括号
		for(int i = 1;i <= a;i++) cout<<ansa[i]<<' ';//左括号下标
		for(int i = b;i >= 1;i--) cout<<ansb[i]<<' ';//右括号下标
	}//升序输出
	return 0;
}
