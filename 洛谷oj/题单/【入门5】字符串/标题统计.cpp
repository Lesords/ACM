#include<iostream>//ac
#include<string>
using namespace std;
int main() {
	int ans = 0;
	string s;
	getline(cin,s);//∂¡»Î“ª––
	for(int i = 0;i < s.size();i++) {
		if(s[i]!=' ') ans++;
	}
	cout<<ans<<endl;
	return 0;
}
