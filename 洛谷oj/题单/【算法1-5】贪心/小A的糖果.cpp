#include<iostream>//ac
#define ll long long
using namespace std;
const int MAXN = 2e5 + 5;
ll a[MAXN];
int main() {
	ll n,x,ans = 0,tmp;//需要ll ！！！
	cin>>n>>x;
	for(int i = 1;i <= n;i++) {
		cin>>a[i];
		if(a[i]>x) {//先添加自身大于x
			ans += a[i]-x;
			a[i] = x;
		}
	}//当前位 + 前一位 判断糖果数这样不会重复
	for(int i = 2;i <= n;i++) {//从2开始！！！
		if(a[i]+a[i-1]>x) {
			tmp = a[i]+a[i-1]-x;
			ans += tmp;
			a[i] -= tmp;
		}
	}
	cout<<ans<<endl;
	return 0;
}
