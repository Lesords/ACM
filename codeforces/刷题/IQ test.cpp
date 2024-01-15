#include<iostream>
#include<cstring>
using namespace std;
int a[105],n,odd,even;
int main() {
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		a[i]%2?odd++:even++;
	}
	if(odd>even) {
		for(int i=1;i<=n;i++) {
			if(a[i]%2==0) {
				cout<<i<<endl;
				break;
			}
		}
	}
	else {
		for(int i=1;i<=n;i++) {
			if(a[i]%2!=0) {
				cout<<i<<endl;
				break;
			}
		}
	}
	return 0;
}
