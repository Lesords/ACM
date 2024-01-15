#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n,m,a[102],b[102];
	cin>>n;
	for(int i = 1; i <= n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	cin>>m;
	for(int i = 1; i <= m; i++) {
		cin>>b[i];
	}
	sort(b+1,b+1+m);
	cout<<a[n]<<' '<<b[m]<<endl;//max value
	return 0;
}
