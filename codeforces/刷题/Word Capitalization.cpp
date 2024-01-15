#include<stdio.h>
char a[105];
int main()
{
	scanf("%s",a);
	if(a[0]>=97&&a[0]<=122) 
	  a[0]-=32;
	printf("%s\n",a);
	return 0;
} 
