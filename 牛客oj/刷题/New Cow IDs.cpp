#include<iostream>//ac
using namespace std;
int main() {
	int n,tmp = 0,ans;
	cin>>n;
	ans = n;
	while(n) {
		tmp = tmp * 10 + n%10;
		n /= 10;
	}
	cout<<ans+tmp<<endl;
	return 0;
}
