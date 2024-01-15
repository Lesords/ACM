#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;

//题意：求一组数据有多少个共同因数
//题解：先求出最大公约数，然后判断这个数有多少个因子
//因子的个数即为答案

ll gcd(ll a,ll b) {//求最大公约数（爆int,需ll类型）
	return a%b==0?b:gcd(b,a%b);
}
int main() {
	ll n,num,tmp,ans = 0;
	cin>>n>>num;
	for(int i = 2;i <= n;i++) {
		cin>>tmp;
		num = gcd(num,tmp);//先求出所有数的最大公约数
	}
	for(ll i = 1;i*1LL*i <= num;i++) {//爆int，转成ll型计算
		if(num%i==0) {//计算因子数量
			ans += (i==num/i)?1:2;
		}//两个因子相同加1，否则加2
	}
	cout<<ans<<endl;
	return 0;
}
