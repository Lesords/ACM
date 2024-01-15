#include<iostream>
#include<cstring>
using namespace std;
int main() {
	char a[201];
	cin>>a;
	for(int i=0;i<strlen(a);) {
		if(a[i]=='W'&&a[i+1]=='U'&&a[i+2]=='B') {
			cout<<" ";
			i+=3;
		}
		else {
			cout<<a[i];
			i++; 
		}
	}
	return 0;
}
