#include<stdio.h>
int book[500],a[500];
int main()
{
	int i,n,max=0,ans;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]>=0)
		{
			book[a[i]]++;
			if(book[a[i]]==max)
			{
				if(a[i]>ans);
				else
				{
					max=book[a[i]];
					ans=a[i];
				}
			}
			if(book[a[i]]>max)
			{
				max=book[a[i]];
				ans=a[i];
			}
		} 
		else
		{
			book[a[i]+300]++;
			if(book[a[i]+300]==max)
			{
				if(a[i]>ans);
				else
				{
					max=book[a[i]+300];
					ans=a[i];
				}
			}
			if(book[a[i]+300]>max)
			{
				max=book[a[i]+300];
				ans=a[i];
			}
		}
	}
	printf("%d %d",ans,max);
	return 0;
}
