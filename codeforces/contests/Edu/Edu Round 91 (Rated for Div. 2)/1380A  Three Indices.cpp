#include<iostream>//ac
#include<cstdio>
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
const int MAXN = 1005;
int a[MAXN];
int main() {
	int t,n;
	cin>>t;
	while(t--) {
		cin>>n;
		for(int i = 1;i <= n;i++) cin>>a[i];
		int flag = 0,ans;
		for(int i = 2;i < n;i++) {
			//暴力找中间值大于左右即可
			if(a[i]>a[i-1]&&a[i]>a[i+1]) {
				flag = 1;
				ans = i;
				break;
			}
		}
		if(flag) {
			cout<<"YES\n"<<ans-1<<' '<<ans<<' '<<ans+1<<endl;
		}
		else cout<<"NO\n";
	}
	return 0;
}
