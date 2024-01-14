#include<iostream>
#include<stack>
#include<cstring>
#include<string>
#include<algorithm> 
using namespace std;
string a,b;
stack<int> s;
char ans[200]; //保存操作 
bool issame(string a, string b) {
	if(a.length()!=b.length()) return false;
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	return a==b;
}
void dfs(int x,int y) {
	if(x+y==2*a.length()) {//i和o的操作和为a的两倍 
		for(int i=0;i<x+y;i++) {
			cout<<ans[i]<<' '; 
		}
		cout<<endl;
	}
	if(x<a.length()) {//只有 i 满的时候才开始递归 o
		s.push(a[x]);
		ans[x+y]='i';
		dfs(x+1,y);
		s.pop(); //输入分支关键点 
	}
	if(!s.empty()&&s.top()==b[y]) {
		char tmp=s.top();
		s.pop();
		ans[x+y]='o';
		dfs(x,y+1);
		s.push(tmp);//将字符放回，判断其他可能性 
	}
}
int main() {
	while(cin>>a>>b) {
		cout<<"["<<endl;
		if(issame(a,b)) dfs(0,0);//从零开始 
		cout<<"]"<<endl;
	}
	return 0;
}
 
