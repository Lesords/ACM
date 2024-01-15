#include<iostream>//ac
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	string a,b;
	int sum = 0,begin = -1;
	cin>>a;
	getchar();//吸收第一行末尾字符串
	transform(a.begin(),a.end(),a.begin(),::tolower);//转化成小写
	getline(cin,b);//getline函数以 回车符 为结束！！！
	string tmp = "";
	int start = 0;//初始化单词起始位置
	for(int i = 0;i < b.size();i++) {
		if(b[i] == ' '||i == b.size()-1) {
			if(i == b.size()-1) tmp += b[i];
			transform(tmp.begin(),tmp.end(),tmp.begin(),::tolower);
			if(tmp==a) {
				if(begin==-1) begin = start;//还没保存初始位置
				sum++;
			}
			tmp = "";
			start = i + 1;//更新初始位置
		}
		else tmp += b[i];
	}
	if(sum) {
		cout<<sum<<' '<<begin<<endl;
	}
	else cout<<"-1"<<endl;
	return 0;
}
