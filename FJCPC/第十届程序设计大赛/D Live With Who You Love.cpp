#include<iostream>//?
#include<set>
#include<algorithm>
#define ll long long
using namespace std;
const int MAXN = 2e5+10;
ll pow(ll a,ll b) {
	ll ans = 1;
	for(int i = 1;i <= b;i++) {
		ans *= a;
	}
	return ans;
}
ll ans[MAXN];
int main() {
	int t;
	cin>>t;
	while(t--) {
		ll a,b,c,L,R,cnt = 0;
		set<ll> ss;
		cin>>a>>b>>c>>L>>R;
		for(int i = 0;i <= 64;i++) {
			if(pow(a,i)>R) break;
			for(int j = 0;j <= 64;j++) {
				if(pow(a,i)+pow(b,j)>R) break;
				for(int k = 0;k <= 64;k++) {
					ll tmp = pow(a,i)+pow(b,j)+pow(c,k);
					if(tmp>R) break;
					if(ss.count(tmp)) continue;
					if(tmp>=L) {
						ans[++cnt] = tmp;
						ss.insert(tmp);
					}
				}
			}
		}
		sort(ans+1,ans+cnt+1);
		/*for(int i = 1;i <= cnt;i++) {
			if(i!=1) cout<<' ';
			cout<<ans[i];
		}
		cout<<endl;*/
		ll num = max(ans[1]-L,R-ans[cnt]);
		for(int i = 2;i <= cnt;i++) {
			num = max(num,ans[i]-ans[i-1]-1);
		}
		cout<<num<<endl;
	}
	return 0;
}
