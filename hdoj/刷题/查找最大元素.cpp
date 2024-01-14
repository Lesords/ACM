#include<iostream>
#include<cstring>
using namespace std;
char n[105];
int main() { 
	while(cin>>n) {
		char ch = ' ';
		for(int i=0;i<strlen(n);i++) {
			if(n[i]>ch) ch = n[i];//±ê¼Ç 
		}
		for(int i=0;i<strlen(n);i++) {
			if(n[i] == ch) cout<<ch<<"(max)";
			else cout<<n[i];
		}
		cout<<endl;
	}
	return 0;
} 
