#include<iostream>//ac
#include<string>
using namespace std;
int a[30] = {1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};
int main() {
	string s;
	getline(cin,s);//读入一行
	int ans = 0;
	for(int i = 0;i < s.length();i++) {
		if(s[i]>='a'&&s[i]<='z') ans += a[s[i]-'a'];
		if(s[i]==' ') ans++;//单独判断，有奇怪的字符
	}//有 '\n' 和 '\r'
	cout<<ans<<endl;
	return 0;
}
