#include<iostream>//wa
#include<cstdio>
#include<cmath>
#include<string>
#include<queue>
#include<vector>
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;
const int MAXN = 2e6+5;
const int MOD = 1e9+7;
struct node{
	int u,v;
	friend bool operator < (node a,node b) {
		if(a.u!=b.u) return a.u < b.u;
		return a.v < b.v;
	}
}a[MAXN];
ll dis[MAXN];
int main() {
	int n,m,u,v;
	ll ans = 0;
	scanf("%d%d",&n,&m);
	for(int i = 2;i <= n;i++) dis[i] = INF;
	for(int i = 1;i <= m;i++) {
		scanf("%d%d",&u,&v);
		a[i].u = min(u,v);
		a[i].v = max(u,v);
	}
	sort(a+1,a+1+m);
	for(int i = 1;i <= m;i++) {
		if(a[i].u==1) {
			dis[a[i].v] = 1;
		}
		else if(dis[a[i].u]>=1) {
			dis[a[i].v] = min(dis[a[i].v],dis[a[i].u]+1);
		}
	}
	for(int i = 2;i <= n;i++) {
		ans = (ans+(1<<dis[i])%MOD)%MOD;
	}
	cout<<ans;
	return 0;
}
