#include<cstdio>//ac
using namespace std;
const int MAXN = 1e5+5;
int a[MAXN],pre[MAXN];
int main() {
	int n,k,l,r;
	scanf("%d%d",&n,&k);
	for(int i = 1;i <= n;i++) {
		scanf("%d",&a[i]);
		pre[i] = pre[i-1]+a[i];
	}
	while(k--) {
		scanf("%d%d",&l,&r);
		printf("%d\n",pre[r]-pre[l-1]);
	}
	return 0;
}
