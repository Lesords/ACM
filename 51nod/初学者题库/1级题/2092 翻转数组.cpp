#include<iostream>//ac
using namespace std;
const int MAXN = 1e5 + 5;
int a[MAXN];
int main() {
	int n;
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1;i <= n;i++) cin>>a[i];
	cout<<n<<endl; 
	for(int i = n;i >= 1;i--) cout<<a[i]<<endl;
	return 0;
}
