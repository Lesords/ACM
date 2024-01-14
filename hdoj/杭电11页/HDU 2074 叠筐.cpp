#include<iostream>//ac
using namespace std;
int main() {
	int n,flag = 0;
	char a,b;
	while(cin>>n>>a>>b) {
		int mid = n/2+1;
		char tmp;
		int cnt = (n-1)/2;
		if(cnt%2) {
			tmp = a;
			a = b;
			b = tmp;
		} 
		if(flag++) cout<<endl;
		if(n==1) {
			cout<<a<<endl;
			continue;
		}
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++) {
				if((i==1||i==n)&&j==1&&n!=1) {
					cout<<' ';
					continue;
				}
				if((i==1||i==n)&&j==n) {
					cout<<' ';
					continue;
				}
				if(i==1||j==1||i==n||j==n) {
					cout<<a;
					continue; 
				}
				if(i<=j&&j<=n-i+1&&i<=mid&&i%2) {
					cout<<a;//×îÍâ²ã
					continue;
				}
				if(n-i+1<=j&&j<=i&&i>mid&&i%2) {
					cout<<a;
					continue;
				}
				if(j<=i&&i<=n-j+1&&j<=mid&&j%2) {
					cout<<a;
					continue;
				}
				if(n-j+1<=i&&i<=j&&j>mid&&j%2) {
					cout<<a;
					continue;
				}
				cout<<b;
			}
			cout<<endl;
		}
	}
	return 0;
} 
