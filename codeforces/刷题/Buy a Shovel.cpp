#include<iostream>
using namespace std;
int main() {
	int k,r,cnt=1,tmp;
	cin>>k>>r;
	tmp=k%=10;
	while(k!=r&&k) {
		k+=tmp;
		k%=10;
		cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}
