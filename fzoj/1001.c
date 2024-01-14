#include<stdio.h>
#include<string.h>
int book[1000005];
int main()
{
	int n,i,cnt;
	while(scanf("%d",&n)!=EOF)
	{
		memset(book,0,sizeof(book));
		for(i=1;i<=n;i++)
		{
			scanf("%d",&cnt);
			book[cnt]++;
		} 
		for(i=1;i<=n;i++)
		{
			if(book[i]==2)
			printf("%d\n",i);
		}
	}
	return 0;
} 
