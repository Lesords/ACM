#include<iostream>
using namespace std;
int main() {
	int T;
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--) {
		int a[5],n;
		cin>>a[0]>>a[1]>>n;
		a[2]=a[0]^a[1];
		cout<<a[n%3]<<endl;//异或操作是循环数	
	}
	return 0;
}
