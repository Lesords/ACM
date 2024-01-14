#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
using namespace std;
char b[3003];//gets函数不支持string输入 
int main() {
	string s,a;
	map<string, string> map;
	cin>>a;//START（省略）
	while(cin>>a&&a!="END") {
		cin>>b;
		map[b]=a;
	}
	cin>>a;//START（省略）
	getchar();//START末尾的回车符
	s="";//初始化
	while(gets(b)&&strcmp(b,"END")) {//整行输入
		int len=strlen(b);
		for(int i=0;i<len;i++) {
			if(b[i]<'a'||b[i]>'z') {//标点符号
				if(map[s]!="") cout<<map[s];//转换存在，输出
				else cout<<s;
				cout<<b[i];//标点符号（当前）
				s="";//清空
			}
			else s+=b[i];
		}
		cout<<endl;//pe点 
		s="";//初始化 
	}
	return 0;
} 
