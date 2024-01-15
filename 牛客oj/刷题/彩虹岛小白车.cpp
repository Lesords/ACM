#include<iostream>//ac
using namespace std;
int main() {
	int t,a,b,c,d;
	cin>>t;
	while(t--) {
		cin>>a>>b>>c>>d;
		if(a <= (c-d)+b) cout<<"Walk"<<endl;
		else cout<<"Bus"<<endl;
	}
	return 0;
}
