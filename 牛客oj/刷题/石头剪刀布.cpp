#include<iostream>//ac
using namespace std;
int main() {
	int t;
	char a[15];
	cin>>t;
	while(t--) {
		cin>>a;
		if(a[0] == 'S') cout<<"Rock"<<endl;
		else if(a[0] =='R') cout<<"Paper"<<endl;
		else cout<<"Scissors"<<endl;
	}
	return 0;
}
