#include<iostream>//ac
using namespace std;
int main() {
	int t,n,w,q;
	cin>>t;
	while(t--) {
		cin>>n>>w>>q;
		int max_w = 0,max_q = 0, tmp;
		for(int i = 1;i <= n;i++) cin>>tmp, max_w += tmp;
		for(int i = 1;i <= n;i++) cin>>tmp, max_q += tmp;
		if(max_w<=w&&max_q<=q) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
} 
