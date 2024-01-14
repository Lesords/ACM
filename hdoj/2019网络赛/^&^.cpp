#include<iostream>
using namespace std;
long long a,b,c;
int main() {
	int t;
	cin>>t;
	while(t--) {
		cin>>a>>b;
		c=a&b;//取a与b两者中都有的1，在异或运算中会将1转为0 
		if(c==0) cout<<"1"<<endl;
		else cout<<c<<endl;
	}
	return 0;
}
