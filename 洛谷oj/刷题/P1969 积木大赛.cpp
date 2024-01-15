#include<iostream>//ac
#define ll long long
using namespace std;
const int MAXN = 1e5+5;
int a[MAXN];
int main() {
	int n;
	cin>>n;
	for(int i = 1;i <= n;i++) cin>>a[i];
	//从第一个开始搭积木
	ll ans = a[1];
	//后面的积木如果小于前面的话，可以一起搭
	//如果大于前面的话，需要在搭大于的部分
	for(int i = 2;i <= n;i++) {
		//后面大于前面，再搭差值
		if(a[i]>a[i-1]) ans += a[i]-a[i-1];
	}
	cout<<ans;
	return 0;
}
