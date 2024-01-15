#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;
const int MAXN = 2e5+5;
ll a[MAXN],n,k,ans;//需要ll！！！
bool check(ll siz) {//siz为大小
	ll num = 0;
	for(int i = 1;i <= n;i++) {
		num += a[i]/siz;//统计数量
	}
	return num >= k;//判断数量是否够
}
int main() {
	cin>>n>>k;
	for(int i = 1;i <= n;i++) cin>>a[i],ans += a[i];
	//ans统计总长度，然后可得出最大值 r
	ll l = 1,r = ans/k;//ans爆int了！！！
	ans = 0;//再次利用于答案的计算
	while(l<=r) {
		ll mid = (l+r)/2;
		//更新ans，并且移动l，需加1，否则l会一直等于r!!!
		if(check(mid)) ans = max(ans,mid),l = mid+1;
		else r = mid-1;
	}
	cout<<ans;
	return 0;
}
