#include<iostream>//ac
using namespace std;
int main() {
	int t,x,y;
	cin>>t;
	while(t--) {
		cin>>x>>y;//x>3时，可以转换为任意数字
		if(x==y||x>3||x>y) cout<<"YES"<<endl;
		else if(x*3==y*2) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
