#include<iostream>//ac
#define ll long long
using namespace std;
int main() {
	ll n,x,ans = 0;
	cin>>n>>x;
	for(int i = 1;i <= n;i++)
		if(!(x%i)&&(x/i)<=n) ans++;
		//可整除且另个乘数小于等于n
	cout<<ans<<endl;
	return 0;
} 
