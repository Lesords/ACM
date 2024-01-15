#include<iostream>//ac
using namespace std;
int main() {
	int n,m,a,b;
	cin>>n>>m>>a>>b;
	if(b*1.0/m*1.0>=a) {//多程票不便宜
		cout<<n*a<<endl;
	}
	else {
		if(n%m) {
			if(n%m*a>b) cout<<n/m*b+b<<endl;//多票比单票便宜
			else cout<<n/m*b+n%m*a<<endl;
		}
		else cout<<n/m*b<<endl;//多程票刚好
	}
	return 0;
} 
