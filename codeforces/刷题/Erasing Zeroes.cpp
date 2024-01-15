#include<iostream>//ac
#include<string>
using namespace std;
int main() {
	int t;
	string s;
	cin>>t;
	while(t--) {
		cin>>s;
		int ans = 0;
		if(s.size()==1) {//特判字符串大小为1
			cout<<"0"<<endl;
			continue;
		}
		while(s[0]=='0') s.erase(0,1);//删除前置0和后置0
		while(s[s.size()-1]=='0') s.erase(s.size()-1,s.size());
		for(int i = 0;i < s.size();i++) {
			if(s[i]!='1') ans++;//计算中间部分有多少不是1
		}
		cout<<ans<<endl;
	}
	return 0;
}
