#include<iostream>//ac 差分做法
#include<algorithm>
#define ll long long
using namespace std;

//差分为当前值 - 前一个值
//维护的时候判断位置即可
//取值的时候为 当前值 = 前一个值+差分

//也就是说差分就是前后两个数的差值

const int MAXN = 2e5+5;
ll a[MAXN];
int main() {
	int n,m,l,r;
	ll ans = 0;
	cin>>n>>m;
	while(m--) {
		cin>>l>>r;
		a[l]++,a[r+1]--;//修改差分
	}
	//取值
	for(int i = 1;i <= n;i++) a[i] += a[i-1];
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++) ans += a[i]*i;
	cout<<ans;
	return 0;
}
