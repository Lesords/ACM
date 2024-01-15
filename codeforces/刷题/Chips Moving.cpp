#include<iostream>
using namespace std;
int a[105];
int main() {
	int t,ans1=0,ans2=0,ans;
	cin>>t;
	for(int i=1;i<=t;i++) {
		cin>>a[i];
		a[i]%=2;
		a[i]?ans1++:ans2++;
	}
	ans=ans1>ans2?ans2:ans1;
	cout<<ans<<endl;
	return 0;
} 
