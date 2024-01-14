#include<iostream>
using namespace std;
int main() {
	long long n,m;
	while(cin>>n>>m) {
		for(int i=2;i<=m;i++) {
			if(n%2) n*=2;
			else n--;
			n%=100000007;
		}
		cout<<n<<endl;
	}
	return 0;
} 
