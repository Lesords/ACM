#include<iostream>//ac
using namespace std;
int b,p,k;
int poww(int a,int b) {
	//if(!b) return 1%k;//特判指数为0时！！！
	int ans = 1, bas = a%k;//初始值需 %k！！！
	while(b) {
		if(b&1) ans = (bas*ans)%k;
		bas = (bas*bas)%k;//累乘
		b >>= 1;//右移一位
	}
	return ans%k;//结果需%k，防止出现b为0的情况！！！
}
// update
ll poww(ll a, ll b, ll p) {//a的b次方
	ll ans = 1;//ans为结果
	while(b) {
		if(b&1) ans = (ans*a)%p;
		a = (a*a)%p;//二进制每次乘都要翻倍 
		b >>= 1;
	}
	return ans%p;   
}
int main() {
	cin>>b>>p>>k;
	cout<<b<<'^'<<p<<' '<<"mod "<<k<<'='<<poww(b,p);
	return 0;
}
