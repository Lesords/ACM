#include<iostream>//ac
using namespace std;
int main() {
	int t,n,m;
	cin>>t;
	while(t--) {
		cin>>n>>m;
		if(n>=m) cout<<m<<endl;//房间过多,直接输出装置数
		else {
			if(m%n==0) cout<<n*(m/n)*(m/n)<<endl;//可平分
			else {
				//平分之后，多出来的装置数一个个房间分配即可
				int mod = m%n;//多出来的装置数（房间数）
				int res = n - mod;//剩余可平分的房间数
				m -= mod;//去除多的装置数
				cout<<mod*(m/n+1)*(m/n+1)+res*(m/n)*(m/n)<<endl;
			}
		}
	}
	return 0;
}
