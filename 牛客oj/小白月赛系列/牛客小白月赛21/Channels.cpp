#include<iostream>//ac (前缀和思想)
#define ll long long
using namespace std;
ll f(ll n) {
	ll ans = 0;
	ans += (n/60)*50;//时间段数量 * 有效时间（50）
	n %= 60;//剩余时间
	if(n>50) ans += 50;//最多只有50
	else ans += n;
	return ans;
}
int main() {
	ll s,e;
	while(cin>>s>>e) {//起点也为有效观看时刻
		cout<<f(e)-f(s-1)<<endl;//起点前一位
	}
	return 0;
}
