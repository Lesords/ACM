#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[10001];
int main() {
	int n;
	ios::sync_with_stdio(false);
	memset(a,0,sizeof(a));
	for(int i=2;i<=10000;i++) {
		if(a[i]==0)
			for(int j=i+i;j+i<=10000;j+=i) a[j]=1;
	}
	while(cin>>n) {
		for(int i=n/2;i>=2;i--) {
			if(a[i]==1) continue;
			if(a[n-i]==1) continue;
			cout<<i<<' '<<n-i<<endl;
			break;
		}
	}
	return 0;
}
