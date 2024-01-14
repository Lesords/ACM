#include<iostream>
#include<cstring>
using namespace std;
int main() {
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) {
		char ch;
		int x;
		cin>>ch>>x;
		if(ch>='A'&&ch<='Z') {
			cout<<ch-'A'+1+x<<endl;
		}
		else {
			cout<<-(ch-'a'+1)+x<<endl;
		}
	}
	return 0;
}
