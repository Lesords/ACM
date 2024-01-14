#include<iostream>//ac
#include<cstring>
#include<cstdio>
using namespace std;
int cycle,a,b,start;
int num[3005],book[3005];//最大余数以及位数不超过3000
void solve() {
	int cnt = 1;
	while(!book[a]&&a) {//a为0(可除尽)或余数a已存在(循环点)
		book[a] = cnt;//记录位数（a为余数）
		num[cnt++] = a*10/b;//num数组保存商
		a = a*10%b;//更新余数
	}
	if(!a) {//可除尽
		for(int i = 1;i < cnt;i++) cout<<num[i];
		cout<<"(0)"<<endl<<"   1";
	}
	else {//循环小数
		for(int i = 1;i < book[a];i++) cout<<num[i];//非循环
		cout<<'(';
		for(int i = book[a];i < cnt;i++) {
			if(i>50) {
				cout<<"...";//超过50
				break;
			}
			cout<<num[i];
		}
		cout<<')'<<endl<<"   "<<cnt - book[a];
		//循环长度 = 周期截止长度 - 非循环长度！！！
	}
}
int main() {
	while(cin>>a>>b) {
		memset(book,0,sizeof(book));
		cout<<a<<'/'<<b<<" = "<<a/b<<'.';//先输出整数部分
		a %= b;//求余(去掉被除掉的数值)
		solve();
		cout<<" = number of digits in repeating cycle"<<endl<<endl;
	}
	return 0;
}
