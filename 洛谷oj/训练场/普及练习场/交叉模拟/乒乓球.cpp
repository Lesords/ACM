#include<iostream>//ac
#include<string>
#include<algorithm>
using namespace std;
string s[2510];
int cnt = 1,flag;
void solve(int num) {
	int a = 0,b = 0,maxx,minn;
	flag = 1;
	for(int i = 1;i < cnt&&flag;i++) {//flag判断结束
		for(int j = 0;j < s[i].size();j++) {//每行的长度可能不一样
			if(s[i][j]=='E') {//结束标志
				cout<<a<<":"<<b<<endl;//输出剩余比分
				//即使分数为0也要输出！！！
				flag = 0;break;//结束
			}
			if(s[i][j]=='W') a++;
			else if(s[i][j]=='L') b++;
			maxx = max(a,b);
			minn = min(a,b);
			if(maxx>=num&&maxx-minn>=2) {
			//满足对应分制且分差大于2
				cout<<a<<":"<<b<<endl;
				a = b = 0;//置0
			}
		}
	}
}
int main() {
	while(cin>>s[cnt]) cnt++;//保存输入数据
	solve(11);//11分制
	cout<<endl;
	solve(21);//21分制
	return 0;
}
