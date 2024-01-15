#include<iostream>//ac
//求解最多个数质数和，那么可以分解成n个2或3的和
//偶数即为n个2的和
//奇数的话为(奇数-1)/2个2和一个3的和
using namespace std;
int main() {
	int n;
	cin>>n;
	if(n%2==0) {
		cout<<n/2<<endl;
		for(int i = 1;i <= n/2;i++) {
			if(i!=1) cout<<' ';
			cout<<'2';
		}
		cout<<endl;
	}
	else {
		cout<<(n-1)/2<<endl;
		for(int i = 1;i < (n-1)/2;i++) {
			if(i!=1) cout<<' ';
			cout<<'2';
		}
		cout<<' '<<'3'<<endl;
	}
	return 0;
}
