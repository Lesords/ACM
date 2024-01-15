#include<iostream>//ac
#include<cstdio>
#include<cmath>
#include<string>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<algorithm>
#define ll long long
#define fi first
#define se second
using namespace std;
const int MAXN = 1e5+5;
int main() {
	stack<char> sta;
	string s;
	char tmp;
	cin>>s;
	for(int i = 0;i < s.size();i++) {
		if(sta.empty()) sta.push(s[i]);
		else {
			if(sta.top()==s[i]) sta.pop();//相同则删除
			else sta.push(s[i]);//否则输入
		}
	}
	s = "";
	while(sta.size()) {
		s = sta.top()+s;//反向输出
		sta.pop();
	}
	if(s.empty()) cout<<"0\n";
	else cout<<s;
	return 0;
}
