#include<iostream>//ac
#include<cstdio>
#include<cmath>
#define ll long long
using namespace std;
const int MAXN = 1e6 + 5;
int a[MAXN];
int main() {
	int n;
	ll tmp;
	a[1] = 1;
	for(int i = 2 ;i<MAXN;i++) {
		if(!a[i])
			for(int j = i+i;j<MAXN;j += i) a[j] = 1;
	}
	cin>>n;
	while(n--) {
		scanf("%lld",&tmp);
		ll mid = sqrt(tmp);//开平方数为整数，且此平凡数为素数
		if(mid*mid == tmp && !a[mid]) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
