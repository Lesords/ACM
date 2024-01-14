#include<iostream>//ac
using namespace std;
const int MAXN = 1e5 + 5;
int a[MAXN];
int main() {
	int n,tmp;cin>>n;
	for(int i = 1;i <= n;i++) {
		cin>>tmp;
		a[i] = tmp + a[i-1];
	} 
	cout<<n<<endl;
	for(int i = 1;i <= n;i++) cout<<a[i]<<endl;
	return 0;
} 
