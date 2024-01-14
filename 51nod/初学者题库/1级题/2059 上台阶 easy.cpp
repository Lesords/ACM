#include<iostream>//ac
using namespace std;
int a[30];
int main() {
	a[1] = a[2] = 1;
	for(int i = 3;i <= 27;i++) a[i] = a[i-1] + a[i-2];
	int n;
	cin>>n;
	cout<<a[n]<<endl;
	return 0;
}
