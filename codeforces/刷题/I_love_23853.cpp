#include<iostream>//ac
using namespace std;
int a[1005];
int main() {
	int T,min,max,ans=0;
	cin>>T;
	for(int i=1;i<=T;i++) {
		cin>>a[i];
		if(i==1) {
			min=max=a[i];
			continue;
		}
		if(a[i]>max) {
			ans++;
			max = a[i];
		}
		if(a[i]<min) {
			ans++;
			min = a[i];
		}
	}
	cout<<ans<<endl;
	return 0;
}
