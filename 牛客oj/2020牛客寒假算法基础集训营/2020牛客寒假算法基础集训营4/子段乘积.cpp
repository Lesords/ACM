#include<iostream>//ac
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int MAXN = 2e5+5;
const int MOD = 998244353;
ll sum[MAXN<<2],a[MAXN];
void build(int l,int r,int rt) {
	if(l==r) {
		sum[rt] = a[l];
		return ;
	}
	int mid = (l+r)>>1;
	build(l,mid,rt<<1);
	build(mid+1,r,rt<<1|1);
	sum[rt] = sum[rt<<1] * sum[rt<<1|1]%MOD;
}
ll query(int L,int R,int l,int r,int rt) {//LR´óÇø¼ä
	ll ans = 1;
	if(l<=L&&R<=r) return sum[rt];
	int mid = (L+R)>>1;
	if(l<=mid) ans = ans * query(L,mid,l,r,rt<<1)%MOD;
	if(r>mid) ans = ans * query(mid+1,R,l,r,rt<<1|1)%MOD;
	return ans%MOD;
}
int main() {
	int k,n;
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll ans = 0;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	build(1,n,1);
	for(int i = 1;i+k-1<=n;i++) {
		ans = max(ans,query(1,n,i,i+k-1,1)%MOD);
	}
	cout<<ans%MOD<<endl;
	return 0;
}
