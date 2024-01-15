#include<iostream>//ac
using namespace std;
char code[30];//密文转原文（保存原文）
int book[30];//标记已有的原文字符
int main() {
	string a,b,c;
	cin>>a>>b>>c;//a密文，b原文
	int num = 0,flag = 1;
	for(int i = 0;i < a.size()&&flag;i++) {
		int tmp = a[i] - 'A';
		if(code[tmp]) {//存在密转原
			if(b[i]!=code[tmp]) {//两个原文不一样
				flag = 0;break;//有冲突
			}
		}
		else {//新的密转原 
			if(book[b[i]-'A']) {//原文已存在
				flag = 0;break;//原文对应多个密文！！！
			}
			num++;//数量++
			code[tmp] = b[i];//保存对应的原文
			book[b[i]-'A'] = 1;//标记当前原文
		}
	}//只能一对一，不能多对多或一对多
	if(!flag||num<26) cout<<"Failed";//共26个字符
	else { 
		for(int i = 0;i < c.size();i++) {
			cout<<code[c[i]-'A'];//输出转换后的原文
		}
	}
	return 0;
}
