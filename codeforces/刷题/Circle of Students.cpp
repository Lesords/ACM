#include<iostream>
#include<cstring>
#include<cmath> 
using namespace std;
int a[205];
int main() {
	int t;
	cin>>t;
	while(t--) {
		int n,flag=0,cnt;
		cin>>n>>cnt;
		for(int i=2;i<=n;i++) {
			cin>>a[i];
			int tmp=abs(cnt-a[i]);
			if(tmp!=1&&tmp!=abs(n-1)) flag=1;
			cnt=a[i];
		}
		/*for(int i=1;i+1<=n;i++) {
			if(abs(a[i+1]-a[i])!=1&&abs(a[i+1]-a[i])!=abs(n-1))
			flag=1;
		}*/
		if(flag) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
	return 0;
}
