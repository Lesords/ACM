#include<iostream>//ac
using namespace std;
int main() {
	int t,n;
	cin>>t;
	while(t--) {
		cin>>n;
		int odd = 0,tmp;
		for(int i = 1;i <= n;i++) {
			cin>>tmp;
			if(tmp%2) odd++;
		}
		//两种不可能，其他都是YES
		if(odd==0||(odd==n&&odd%2==0)) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
	return 0;
}
