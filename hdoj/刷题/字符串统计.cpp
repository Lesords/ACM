#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main() {
	int n;
	char a[105];
	cin>>n;
	for(int i=1;i<=n;i++) {
		int ans=0;
		cin>>a;
		for(int j=0;j<strlen(a);j++) {
			if(a[j]>='0'&&a[j]<='9') ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
} 
