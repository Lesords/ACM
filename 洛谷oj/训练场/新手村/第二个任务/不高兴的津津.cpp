#include<iostream>//ac
using namespace std;
int main() {
	int maxx = 0,a,b,ans = 0;
	for(int i = 1;i <= 7;i++) {
		cin>>a>>b;
		if(a+b>maxx) ans = i,maxx = a+b;
	}
	cout<<ans<<endl;
	return 0;
}
