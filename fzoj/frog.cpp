#include<iostream>
using namespace std;
int main() {
	int T,n,m;
	cin>>T;
	while(T--) {
		cin>>n>>m;
		cout<<n-((4*n-m)/2)<<' '<<(4*n-m)/2<<endl;
	}
	return 0;
}
