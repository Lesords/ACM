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
		//����е㣬Ȼ�����һ�鼴��
		for(int i = 1;i <= n;i++) {
			ans += abs(a[mid] - a[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
} 
