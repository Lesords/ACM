#include<iostream>
#include<cstring>
using namespace std;
int n;
char a[1000005];
int main() {
	int cnt = 1;
	while(cin>>n) {
		if(n==0) break;
		cin>>a;
		cout<<"Test case #"<<cnt++<<endl;
	}
	return 0;
} 
