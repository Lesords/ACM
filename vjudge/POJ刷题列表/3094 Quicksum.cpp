#include<iostream>//ac
#include<string>
using namespace std;
int main() {
	string a;
	while(getline(cin,a)) {//读入一行
		if(a=="#") break;
		int ans = 0;
		for(int i = 0;i < a.size();i++) {
			if(a[i] == ' ') continue;//空格无分
			ans += (i+1)*(a[i]-'A'+1);//位数 * 字符值
		}
		cout<<ans<<endl;
	}
	return 0;
}
