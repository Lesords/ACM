#include<iostream>//ac
#define ll long long
using namespace std;
const int MAXN = 1e5+5;
int a[MAXN];
int main() {
	int n;
	ll ans = 0;
	cin>>n;
	for(int i = 1;i <= n;i++) cin>>a[i],ans += a[i]-i+1;
	cout<<ans;
	return 0;
}
