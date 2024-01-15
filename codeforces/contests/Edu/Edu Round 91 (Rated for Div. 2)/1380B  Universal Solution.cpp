#include<iostream>//ac
#include<cstdio>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;
int main() {
	int t;
	string s;
	cin>>t;
	while(t--) {
		cin>>s;
		char ans;
		int a = 0,b = 0,c = 0;
		for(int i = 0;i < s.size();i++) {
			if(s[i]=='R') a++;
			if(s[i]=='S') b++;
			if(s[i]=='P') c++;
		}
		
		//全部为出现字符最多的胜法字符即可
		//这样不管哪个回合，获得的分数都是最多的
		
		if(a>=b&&a>=c) ans = 'P';//可能出现相等情况！
		if(b>=a&&b>=c) ans = 'R';
		if(c>=a&&c>=b) ans = 'S';
		for(int i = 0;i < s.size();i++) cout<<ans;
		cout<<endl;
	}
	return 0;
}
