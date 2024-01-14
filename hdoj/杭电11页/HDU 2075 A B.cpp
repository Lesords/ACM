#include<iostream>//ac
using namespace std;
int main() {
	int T,a,b;
	cin>>T;
	while(T--) {
		cin>>a>>b;
		if(a%b) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
	return 0;
} 
