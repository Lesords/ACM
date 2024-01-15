#include<iostream>//ac
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
#define ull unsigned long long
using namespace std;
int main() {
	int t,n;
	cin>>t;
	while(t--) {
		cin>>n;
		if(!n) cout<<"1"<<endl;
		else {
			ull ans = 3;
			for(ull a = 2,b = 1;n>1;n--) {
				ull t = b;
				b = a;
				a = b+t;
				ans = a+b;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
