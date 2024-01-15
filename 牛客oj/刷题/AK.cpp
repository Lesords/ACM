#include<iostream>//ac
#include<string>
using namespace std;
int main() {
	int n, flag = 0;
	cin>>n;
	string a;
	string ans;
	while(n--) {
		cin>>a;
		if(a.substr(a.size()-2) == "AK") {//判断最后两位
			flag = 1,ans = a.substr(0,a.size() - 2);
		}
	}
	cout<<ans<<endl;
	return 0;
}
