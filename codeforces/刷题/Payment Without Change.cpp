#include<iostream>//ac
using namespace std;
int main() {
	int t,a,b,n,s;
	cin>>t;
	while(t--) {
		cin>>a>>b>>n>>s;
		int x = min(a,s/n);//x个n值的硬币
		s -= x*n;
		int y = s;//y个1值的硬币
		if(x<=a&&y<=b) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
