#include<stdio.h>
int a[10000],b[10000],book[10000];
int main()
{
	int n,m,i,j,flag;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
		book[a[i]]=1;
		book[b[i]]=1;
	}
	for(i=1;i<=n;i++)
	{
		if(book[i]!=1)
		{
			flag=i;
			break;
		}
	}
	printf("%d\n",n-1);
	for(j=1;j<=n;j++)
	{
		if(j==flag)
		continue;
		printf("%d %d\n",flag,j);
	}
	return 0;
} 
