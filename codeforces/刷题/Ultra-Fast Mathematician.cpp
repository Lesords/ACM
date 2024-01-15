#include<stdio.h>
#include<string.h>
char a[105],b[105];
int main() {
	/*long long a,b,r=1,ans=0;
	scanf("%lld",&a);
	scanf("%lld",&b);
	while(a!=0||b!=0) {
		if(a&1||b&1) {
			ans+=r;
			printf("%lld\n",ans);
		}
		r*=10;
		a>>=1;
		b>>=1;
	}
	printf("%lld\n",ans);*/ 
	scanf("%s",a); 
	scanf("%s",b);
	for(int i=0;i<strlen(a);i++) {
		printf("%d",a[i]!=b[i]);
	}
	return 0;
}
