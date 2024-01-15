#include<stdio.h>
#include<string.h>
char a[105],b[105];
int main()
{
	int ans;
	scanf("%s",a);
	strlwr(a);
	scanf("%s",b);
	strlwr(b);
	if(strcmp(a,b)>0)
	  ans=1;
	else if(strcmp(a,b)==0)
	  ans=0;
	else
	  ans=-1;
	printf("%d\n",ans);
	return 0;
}
