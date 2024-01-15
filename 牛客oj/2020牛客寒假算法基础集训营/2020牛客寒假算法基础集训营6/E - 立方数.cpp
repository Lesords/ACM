#include<iostream>//tle
#include<cstdio>
#include<cmath>
#include<string>
#include<algorithm>
#define ll long long
using namespace std;
const int MAXN = 1e6 + 5;
ll a[MAXN];
int main() {
	int t;
	ll n;
	for(int i = 1;i < MAXN;i++) {
		a[i] = i*i*i;
	}
	scanf("%d",&t);
	while(t--) {
		scanf("%lld",&n);
		ll l = 1,r = n,mid;
		if(r>MAXN) r = MAXN-1,l = 1000;
		while(l<=r) {
			mid = (l+r)/2;
			if(n%a[mid]==0) {
				break;
			}
			if(a[mid]>n) r = mid;
			if(a[mid]<n) l = mid+1;
		}
		printf("%lld\n",mid);
	}
	return 0;
}
