#include<iostream>//ac
using namespace std;
int a[105];
int main() {
	int T,maxx = 0;
	cin>>T;
	for(int i=1;i<=T;i++) {
		cin>>a[i];
		if(a[i]>maxx) maxx = a[i];
	}
	if(T==1) cout<<"0"<<endl;
	else {
		int ans = 0;
		for(int i=1;i<=T;i++) {
			ans += maxx - a[i];
		}
		cout<<ans<<endl;
	}
	return 0;
} 
