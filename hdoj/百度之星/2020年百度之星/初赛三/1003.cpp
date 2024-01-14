#include<iostream>//ac
#include<cstring>
#include<cstdio>
#include<cmath>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;
const int MAXN = 1e5+5;
int main() {
	ll t,n,m;
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--) {
		cin>>n>>m;
		if(m>=n/2) m = n/2;//交换次数过多
		ll ans = m*(n-1)-m*(m-1);//等差求和公式
		ans *= 2;
		ans -= m;
		cout<<max(0ll,ans)<<endl;
	}
	return 0;
}
