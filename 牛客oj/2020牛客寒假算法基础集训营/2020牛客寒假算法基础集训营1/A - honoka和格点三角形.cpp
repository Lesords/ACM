#include<iostream>//ac
using namespace std;

//四种情况
//防止爆ll，记得%MOD

const int MOD = 1e9+7;
int main() {
	long long n,m;
	cin>>n>>m;
	long long ans = ((m-2)*m%MOD*2*(n-1))%MOD;
	ans = (ans+((n-2)*n%MOD*2*(m-1)))%MOD;
	if(n>2) ans = (ans+(m-1)*(m-2)%MOD*(n-2)*2)%MOD;
	if(m>2) ans = (ans+(n-1)*(n-2)%MOD*(m-2)*2)%MOD;
	cout<<ans;
	return 0;
}
