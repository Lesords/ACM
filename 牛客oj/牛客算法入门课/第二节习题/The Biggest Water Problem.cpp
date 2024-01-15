#include<iostream>//ac
#define ll long long
using namespace std;
ll solve(ll n) {//求各个数位的总和
	ll ans = 0;
	while(n) {
		ans += n%10;
		n /= 10;
	}
	return ans;
}
int main() {
	ll n;
	cin>>n;
	while(n>=10) {//只要不为个位就一直执行
		n = solve(n);
	}
	cout<<n;
	return 0;
}
