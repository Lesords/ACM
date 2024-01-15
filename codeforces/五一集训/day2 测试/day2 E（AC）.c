#include<stdio.h>
long long n,k,i;
int main()
{
	scanf("%I64d%I64d",&n,&k);
	for(i=1;i<=k*2;i+=2)
	{
		printf("%I64d ",i);
		printf("%I64d ",i+1);
	}
	for(i=2*k+1;i<=2*n;i+=2)
	{
		printf("%I64d ",i+1);
		printf("%I64d ",i);
	}
	return 0;
} 
