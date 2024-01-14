#include<iostream>//ac
#include<string>
using namespace std;
int main() {
	int t;
	string a;
	cin>>t;
	while(t--) {
		cin>>a;
		string b(a,6);//下标6开始到结束
		b = '6' + b;
		cout<<b<<endl;
	}
	return 0;
}
