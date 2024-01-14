#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main() {
	int n,m,a[101],cnt=2;
	for(int i=1;i<=100;i++) {
		a[i]=cnt;
		cnt+=2;
	}
	while(cin>>n>>m) {
		int ans=0;
		cnt=0; 
		for(int i=1;i<=n;i++) {
			ans+=a[i];
			cnt++;
			if(i%m==0||i==n) {
				cout<<ans/cnt;
				if(i!=n) cout<<' ';
				else cout<<endl;
				ans=cnt=0;
			}
		}
	}
	return 0;
}
