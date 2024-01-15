#include<iostream>//ac
#define ll long long
using namespace std;
const int MAXN = 1e5+10;
int a[MAXN],n;
int main() {
	ll ans = 0;
	cin>>n;
	for(int i = 1;i <= n;i++) cin>>a[i];
	ans = a[1];
	//从前往后铺，如果后面下陷小于前面，则前面铺的时候可以把后面的一起铺了
	//如果后面下陷大于前面的时候，需要再铺差值(后面-前面)的大小
	
	//因为所有道路都需要铺，铺高的时候可以把低的一起铺了，
	//但是如果前面是低的话，后面高的部分得再铺一次
	for(int i = 2;i <= n;i++) {
		if(a[i]<=a[i-1]) continue;
		else ans += a[i]-a[i-1];//后面大于前面，铺差值
	}
	cout<<ans;
	return 0;
}
