#include<stdio.h>
int a[100],b[100];
int main()
{
	int n,ans=0;
	int i,j;
	int flag=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i],&b[i]); 
	}
	for(i=1;i<=n;i++)
	{
		flag=0;
		for(j=1;j<=n;j++)
		{
			if(i==j)
			continue;
			if(a[i] == b[j])
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		ans++;
	}
	printf("%d",ans);
	return 0;
} 
