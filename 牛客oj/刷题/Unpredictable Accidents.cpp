#include<iostream>//ac
#include<cstdio>
using namespace std;
int main() {
	int t,n;
	cin>>t;
	while(t--) {
		cin>>n;
		int hour = 12 + n/60;
		int minu = n % 60;
		cout<<hour<<':';
		if(minu<10) cout<<'0';
		cout<<minu<<endl;
	}
	return 0;
}
