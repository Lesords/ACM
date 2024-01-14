#include<iostream>//ac
#include<cmath>
#include<algorithm>
using namespace std;
int a[505];
int main() {
	int t,n;
	cin>>t;
	while(t--) {
		cin>>n;
		for(int i = 1;i <= n;i++) cin>>a[i];
		sort(a+1,a+1+n);
		int mid,ans = 0;
		if(n%2) mid = n/2 + 1;
		else mid = n/2;
		//求出中点，然后遍历一遍即可
		for(int i = 1;i <= n;i++) {
			ans += abs(a[mid] - a[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
} 
