#include<iostream>//wa
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
const int MAXN = 2e5+10;
struct node{
	ll val,index;
	friend bool operator < (node a,node b) {
		return a.val < b.val;
	}
}a[MAXN],b[MAXN];
ll bin_search(ll l,ll r,ll val) {
	ll ans = 0;
	while(l<=r) {
		ll mid = (l+r)/2;
		if(val>=a[mid].val) ans = a[mid].index,l = mid+1;
		else r = mid-1;
	}
	return ans;
}
int main() {
	ll n,m,x,k,y;
	queue<ll> q;
	cin>>n>>m>>x>>k>>y;
	for(int i = 1;i <= n;i++) cin>>a[i].val,a[i].index = i;
	sort(a+1,a+1+n);
	int flag = 0;
	for(int i = 1;i <= m;i++) {
		cin>>b[i].val;
		if(!flag) b[i].index = bin_search(1,n,b[i].val);
		if(i>1&&b[i].index<b[i-1].index) flag = 1;
		else {
			int tmp = b[i].index-b[i-1].index-1;
			if(tmp) q.push(tmp);
		}
	}
	if(flag) {
		cout<<"-1\n";
		return 0;
	}
	ll tmp = n-b[m].index,ans = 0;
	if(tmp) q.push(tmp);
	if(q.empty()) cout<<"0";
	else {
		while(!q.empty()) {
			tmp = q.front();
			if(tmp<k) ans += 1LL*tmp*y;
			else {
				if(x*1.0/k>y*1.0) ans += 1LL*tmp*y;
				else {
					ans += 1LL*tmp/k*x;
					ans += 1LL*(tmp%k)*y;
				}
			}
			q.pop();
		}
		cout<<ans;
	}
	return 0;
}
