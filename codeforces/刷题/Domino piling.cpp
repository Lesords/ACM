#include<stdio.h>
int main()
{
	int n,m,a,b,ans;
	scanf("%d%d",&n,&m);
	a=n/2;
	if(n%2!=0) {
		b=m/2;
		ans=a*m+b;
		printf("%d\n",ans);
	}
	else {
		ans=a*m;
		printf("%d\n",ans);
	}
	return 0;
}
