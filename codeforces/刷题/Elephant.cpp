#include<stdio.h>
int n;
int main()
{
	scanf("%d",&n);
	if(!(n%5)) printf("%d\n",n/5);
	else printf("%d\n",n/5+1);
	return 0;
}
