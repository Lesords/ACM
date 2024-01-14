#include<iostream>
using namespace std;
long long a[51];
int main() {
	int n;
	a[0]=0;
	a[1]=1;
	for(int i=2;i<=50;i++) {
		a[i]=a[i-1]+a[i-2];
	}
	while(cin>>n) {
		if(n==-1) break;
		cout<<a[n]<<endl;
	}
	return 0;
}
