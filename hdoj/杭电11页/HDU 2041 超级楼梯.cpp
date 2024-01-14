#include<iostream>//ac
using namespace std;
int a[45];
int main() {
	int n,tmp;
	cin>>n;
	a[1] = 0, a[2] = 1, a[3] = 2;//要么是前一级，要么是前两级
	for(int i=4;i<=42;i++) a[i] = a[i-1] + a[i-2];
	while(n--) {
		cin>>tmp;
		cout<<a[tmp]<<endl;
	}
	return 0;
} 
