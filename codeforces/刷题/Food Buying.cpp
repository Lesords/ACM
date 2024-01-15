#include<iostream>//ac
#define ll long long
using namespace std;
int main() {
	ll t,n;
	cin>>t;
	while(t--) {
		cin>>n;
		ll ans = 0,cnt = 0;//初始化为0
		while(n>=10) {//大于10
			cnt += n/10;//返现的钱
			n %= 10;//剩余无法返现的钱
			ans += cnt*10;//花费的钱
			n += cnt;//加上返回的钱
			cnt = 0;//清零
		}
		cout<<ans+n<<endl;//ans+剩余的钱
	}
	return 0;
}
