#include<iostream>//ac
using namespace std;
int main() {
	int T,a,b,mis = 0,chr = 0;
	cin>>T;
	while(T--) {
		cin>>a>>b;
		if(a>b) mis++;
		else if(b>a) chr++;
	}
	if(mis==chr) cout<<"Friendship is magic!^^"<<endl;
	else if(mis>chr) cout<<"Mishka"<<endl;
	else cout<<"Chris"<<endl;
	return 0;
} 
