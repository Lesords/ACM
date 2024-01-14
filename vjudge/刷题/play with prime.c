#include<stdio.h>
int book[30000],ans[10000],a[30000];
int main()
{
	int i,j,k,ii,jj,flag=0;
	int top=0,t,n,num=2;
	int book[30000]={1,1,0};
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		for(ii=0;ii<30000;ii++)
		{
			if(book[ii])
			continue;
			for(jj=ii*2;jj<30000;jj+=ii)
			{
				book[jj]=1;
			}
		}
		scanf("%d",&n);
		for(j=1;j<=n;j++)
		{
			scanf("%d",&a[j]);
			if(book[a[j]]!=1)
			book[a[j]]=num;
			top++;
		}
		for(k=0;k<10000;k++)
		{
			if(book[k]==num)
			{
				printf("%d ",k);
				flag=1; 
			}
		}
		if(flag==0)
		printf("%d",-1);
		num++;
		printf("\n");
	}
	return 0;
}
