#include<iostream>//ac
#include<iomanip>
using namespace std;
int f(string a) {
	int len = a.size(),ans = 0,tmp = 1;
	for(int i = len-1;i >= 0;i--) {
		if(a[i]>='0'&&a[i]<='9') ans += (a[i] - '0')*tmp;
		else if(a[i]>='A'&&a[i]<='Z') ans += (a[i] - 'A' + 10)*tmp;
		else if(a[i]>='a'&&a[i]<='z') ans += (a[i] - 'a' + 10)*tmp;
		tmp *= 16;
	}
	return ans;
}
int main() {
	/*int a,b;
	while(cin>>hex>>a>>b) {
		cout<<a+b<<endl;
	}*/
	string a,b;
	while(cin>>a>>b) {
		cout<<f(a)+f(b)<<endl;
	}
	return 0;
}
