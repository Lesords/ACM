#include<iostream>//ac
#include<cstdio>
#include<cmath>
#include<string>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<algorithm>
#define ll long long
#define fi first
#define se second
using namespace std;
const int MAXN = 2e5+5;
int a[MAXN];
ll tmp;
int main() {
	int n,x;
	cin>>n>>x;
	for(int i = 1;i <= n;i++) cin>>a[i],tmp+=a[i];
	sort(a+1,a+n+1);
	if(x>=n) {
		cout<<tmp;
		return 0;
	}
	ll ans = a[n-x]*x;
	for(int i = n-x+1;i <= n;i++) {
		ans += a[i]-a[n-x];
	}
	cout<<ans;
	return 0;
}
