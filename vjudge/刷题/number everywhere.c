#include<stdio.h>
#include<string.h>
char a[100000];
int main()
{
	int i,j,n,top,mid,flag=0;
	scanf("%s",&a);
	top=strlen(a)-1;
	mid=top/2;
	for(i=0,j=top;i<=mid&&top>=mid;i++,top--)
	{
		if(a[i]!=a[top])
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
	printf("not palindrome");
	else
	printf("palindrome");
	return 0;
}
