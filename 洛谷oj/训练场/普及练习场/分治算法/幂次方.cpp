#include<iostream>//ac
#include<string>
using namespace std;
string solve(int n) {
	string ans = "";//初始化字符串
	int pos = 0;//表示当前操作位置
	if(n==0) return "0";//0的值只为0
	while(n) {
		if(n&1) //二进制判断是否需要添加字符
		ans = "2"+(pos==1?"":("("+solve(pos)+")"))+(ans==""?"":"+")+ans;
		//2是必备字符，然后判断是否需要括号
		//如果指数为1，即pos为1时无需添加括号
		//否则递归调用solve函数得出括号内的字符串
		//最后判断是否有"+"，如果原字符串为空则不需要
		n >>= 1,pos++;
	}
	return ans;
}
int main() {
	int n;
	cin>>n;
	cout<<solve(n)<<endl;
	return 0;
}
