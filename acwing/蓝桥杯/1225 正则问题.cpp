#include<iostream>//wrong idea
#include<string>
#include<stack>
#include<algorithm>
using namespace std;
int pos[105];
string s;
int solve(int l,int r) {
	int ans = 0;
	for(int i = l;i <= r;i++) {
		if(s[i]=='(') {
			ans += solve()
		}
	}
}
int main() {
	cin>>s;
	stack<int> sta;
	for(int i = 0;i < s.size();i++) {
		if(s[i]=='(') sta.push(i);
		else if(s[i]==')') {
			pos[sta.top()] = i;
			sta.pop();
		}
	}
	cout<<solve(0,s.size()-1);
	return 0;
}
