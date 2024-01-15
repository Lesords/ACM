#include<iostream>
using namespace std;
int main() {
	int T,b,p,f,h,c;//b buns, p beef, f chicken cutlets
	cin>>T; 
	while(T--) {
		cin>>b>>p>>f>>h>>c;
		int cnt=b/2;
		if(cnt>=p+f) {
			cout<<p*h+f*c<<endl;
		}
		else {
			if(h>c) {
				if(cnt>p) cout<<p*h+(cnt-p)*c<<endl;
				else cout<<h*cnt<<endl;
			}
			else {
				if(cnt>f) cout<<f*c+(cnt-f)*h<<endl;
				else cout<<c*cnt<<endl;
			}
		}
	}
	return 0;
} 
