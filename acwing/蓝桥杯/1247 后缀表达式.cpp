#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;
const int MAXN = 2e5+5;
ll a[MAXN];//数值过大爆int
int main() {
	ll n,m,sum = 0;
	cin>>n>>m;
	for(int i = 1;i <= n+m+1;i++) cin>>a[i],sum += a[i];
	if(m==0) {//只有加法操作直接输出总和即可
		cout<<sum<<endl;
		return 0;
	}
	sort(a+1,a+n+m+2);//从小到大排序
	//剩余三种情况，全负数，全非负数，负数+非负数
	if(a[1]<=0&&a[n+1+m]>=0) {//既有非负数也有非正数
		ll ans = 0;//只有有负号就能转为正
		for(int i = 1;i <= n+m+1;i++) ans += abs(a[i]);
		cout<<ans<<endl;
		return 0;
	}
	else if(a[1]<0&&a[n+1+m]<0) {//只有负数
		ll ans = a[n+1+m];//将绝对值最小的放在第一位，剩余的总会成正
		//加法操作的负数放在括号内，减法操作则直接操作可为正
		for(int i = 1;i <= n+m;i++) ans += abs(a[i]);
		cout<<ans<<endl;
		return 0;
	}
	ll ans = a[n+1+m];//只有非负整数
	for(int i = 1;i <= m;i++) ans -= a[i];//减小的
	for(int i = m+1;i <= n+m;i++) ans += a[i];//加大的
	cout<<ans<<endl;
	return 0;
}
