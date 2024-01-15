#include<iostream>//ac
#include<cstdio>
#include<cmath>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;
int gcd(int a,int b) {
	return a%b==0?b:gcd(b,a%b);
}
int main() {
	int t,n,a,b;
	cin>>t;
	while(t--) {
		cin>>n>>a>>b;
		int num;
		num = n/gcd(a,b)-2;
		if(num%2) cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}
