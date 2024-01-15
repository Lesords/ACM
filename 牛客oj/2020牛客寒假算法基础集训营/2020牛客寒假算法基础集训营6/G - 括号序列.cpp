#include<iostream>//ac
#include<cstdio>
#include<cmath>
#include<queue>
#include<string>
#include<algorithm>
#define ll long long
using namespace std;
int main() {
	int t,n;
	string s;
	cin>>t;
	while(t--) {
		cin>>n>>s;
		if(n==0) cout<<"0\n";
		else {
			queue<char> q;
			int ans = 0;
			for(int i = 0;i < s.size();i++) {
				if(s[i]=='(') q.push('(');
				else {
					if(q.empty()) ans++;
					else q.pop();
				}
			}
			cout<<ans+q.size()<<endl;
		}
	}
	return 0;
}
