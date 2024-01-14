#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
int main() {
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) {
		int a,b;
		cin>>a>>b;
		a%=100;
		b%=100;
		cout<<(a+b)%100<<endl;
	}
	return 0;
} 
