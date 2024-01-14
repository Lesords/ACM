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
ll a[MAXN],b[MAXN],vis[MAXN];
int main() {
	int t,n;
	scanf("%d",&t);
	while(t--) {
		memset(vis,0,sizeof(vis));
		scanf("%d",&n);
		ll x,y,l_num = 0,r_num = 0,ans = 0,l_max = 0,r_max = 0;
		for(int i = 1;i <= n;i++) {
			scanf("%lld%lld",&x,&y);
			if(x==1) {
				b[++r_num] = y;//右车道
				r_max = max(r_max,y);
				vis[y] = 1;
			}
			else {
				a[++l_num] = y;//左车道
			}
		}
		for(int i = 1;i <= l_num;i++) {
			if(vis[a[i]+1]==0) {//可以右移的车
				vis[a[i]+1] = 1;
				r_max = max(r_max,a[i]+1);
				a[i] = 0;
			}
			else l_max = max(l_max,a[i]);
		}
		if(l_max) {//不为0时！！！
			l_max = 4+l_max-1;
		}
		if(r_max) r_max += 1;//不为0时！！！
		ans = max(l_max,r_max);
		cout<<ans<<endl;
	}
	return 0;
}
