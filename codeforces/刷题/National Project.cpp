#include<iostream>//ac
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;
int main() {
	ll t,n,g,b;
	cin>>t;
	while(t--) {
		cin>>n>>g>>b;
		//g>b时，结果为n
		//g<b时，只需要计算好的天数即可（坏的一定满足要求）
		ll tmp = ceil(n/2.0);//高质量的路所需长度
		ll ans = floor(tmp/g)*(g+b);//ans个（好，坏）周期
		if(tmp%g==0) ans -= b;//若刚好修完，则坏的可以不修
		else ans += tmp%g;//继续修好的
		//至少需要n天，以防出现好的天数大于坏的天数！！！
		cout<<max(n,ans)<<endl;
	}
	return 0;
}
