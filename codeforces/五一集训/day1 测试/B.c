#include<stdio.h>
#include<string.h>
int book[1000];
int main()
{
	char a[10000][10],b[10000][10];
	int n,i,j,ans=0,flag;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%s",a[i]); 
	}
	for(i=1;i<=n;i++)
	{
		scanf("%s",b[i]); 
	}
	for(i=1;i<=n;i++)
	{
		flag=1;
		for(j=1;j<=n;j++)
		{
			if(book[j]==1)
			continue;
			if(strcmp(a[i],b[j])==0)
			{
				book[j]=1;
				flag=0;
				break;
			}
		}
		if(flag==1)
		ans++;
	}
	printf("%d",ans);
	return 0;
}
