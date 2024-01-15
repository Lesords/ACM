#include<iostream>
#include<string>
using namespace std;
int main() {
	int T,ans=0;
	string tmp;
	cin>>T;
	while(T--) {
		cin>>tmp;
		if(tmp=="Tetrahedron") ans+=4;
		else if(tmp=="Cube") ans+=6;
		else if(tmp=="Octahedron") ans+=8;
		else if(tmp=="Dodecahedron") ans+=12;
		else ans+=20;
	}
	cout<<ans<<endl;
	return 0;
} 
