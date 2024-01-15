#include<iostream>//ac
#define ll long long
using namespace std;
const int MAXN = 1e5+5;
ll a[MAXN],ans,n,k;
bool check(ll mid) {//判断mid是否可行
	if(mid == 0) return 1;//特判0的情况
	ll num = 0;
	for(int i = 1;i <= n;i++) {
		num += a[i]/mid;//每个木材可以分的段数
	}
	return num >= k;//判断是否够k个
}
int main() {
	cin>>n>>k;
	for(int i = 1;i <= n;i++) cin>>a[i],ans += a[i];
	ll l = 0,r = ans/k;//最小范围为0，最大为 总长/k
	while(l<=r) {//二分答案
		ll mid = (l+r)/2;
		if(check(mid)) {//可行
			ans = mid;//更新答案
			l = mid+1;
		}
		else r = mid-1;
	}
	cout<<ans;
	return 0;
}
