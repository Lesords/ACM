#include<stdio.h>
int main()
{
	long long n,m,a,l1,l2;
	scanf("%lld%lld%lld",&n,&m,&a);
	l1=n/a;
	l2=m/a;
	if(l1*a!=n) l1+=1;
	if(l2*a!=m) l2+=1;
	printf("%lld\n",l1*l2);
	return 0;
}
