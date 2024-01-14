#include<iostream>
using namespace std;
int main() {
	int T,n;
	ios::sync_with_stdio(false); 
	cin>>T;
	while(T--) {
		cin>>n;
		n%2?cout<<n-1<<endl:cout<<n+1<<endl;
	}
	return 0;
} 
