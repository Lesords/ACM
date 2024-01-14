#include<iostream>//ac
using namespace std;
long long a[55],n;//ll型
int main() {
	a[1] = 1,a[2] = 2;
	for(int i=3;i<=52;i++) a[i] = a[i-1] + a[i-2];
	//n为4的时候，可以摆一个竖的(i-1)或者两个横(i-2)的
	while(cin>>n) {
		cout<<a[n]<<endl;
	}
	return 0;
} 
