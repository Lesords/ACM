#include<iostream>//ac
using namespace std;
int main() {
	int n,ans = 0;
	cin>>n;
	while(1) {
		if(n%2) {
			n = n * 3 + 1;
		}
		else n /= 2;
		ans++;
		if(n==1) break;
	}
	cout<<ans<<endl;
	return 0;
} 
