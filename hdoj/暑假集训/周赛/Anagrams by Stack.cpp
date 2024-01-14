#include<iostream>
#include<stack>
#include<cstring>
#include<string>
#include<algorithm> 
using namespace std;
string a,b;
stack<int> s;
char ans[200]; //������� 
bool issame(string a, string b) {
	if(a.length()!=b.length()) return false;
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	return a==b;
}
void dfs(int x,int y) {
	if(x+y==2*a.length()) {//i��o�Ĳ�����Ϊa������ 
		for(int i=0;i<x+y;i++) {
			cout<<ans[i]<<' '; 
		}
		cout<<endl;
	}
	if(x<a.length()) {//ֻ�� i ����ʱ��ſ�ʼ�ݹ� o
		s.push(a[x]);
		ans[x+y]='i';
		dfs(x+1,y);
		s.pop(); //�����֧�ؼ��� 
	}
	if(!s.empty()&&s.top()==b[y]) {
		char tmp=s.top();
		s.pop();
		ans[x+y]='o';
		dfs(x,y+1);
		s.push(tmp);//���ַ��Żأ��ж����������� 
	}
}
int main() {
	while(cin>>a>>b) {
		cout<<"["<<endl;
		if(issame(a,b)) dfs(0,0);//���㿪ʼ 
		cout<<"]"<<endl;
	}
	return 0;
}
 
