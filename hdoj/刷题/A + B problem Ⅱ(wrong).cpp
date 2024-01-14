#include<stdio.h>
long long a,b;
int main() {
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%lld%lld",&a,&b);
		printf("Case %d:\n",i);
		printf("%lld + %lld = %lld\n",a,b,a+b);
		if(i!=n) printf("\n");
	}
	return 0;
} 
