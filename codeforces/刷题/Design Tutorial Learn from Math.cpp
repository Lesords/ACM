#include<iostream>
using namespace std;
const int maxn=1e6+5;
int a[maxn];
int main() {
	for(int i=2;i<maxn;i++) {
		if(!a[i]) {
			for(int j=i+i;j<maxn;j+=i) {
				a[j]=1;
			}
		}
	}
	int n;
	cin>>n;
	for(int i=2;i<n/2+1;i++) {// +1
		if(a[i]&&a[n-i]) {
			cout<<i<<' '<<n-i<<endl;
			break;
		}
	}
	return 0;
} 
