#include<stdio.h>
#include<stdlib.h>
long long n,k,a[200000],book[200000];
long long cnt,num,ans,end;
void dfs(long long step)
{
	long long i,j;
	if(step==2*n+1)
	{
		for(j=1,i=1;j<=n;j++,i+=2)
		{
			num+=a[i]-a[i+1];
			cnt+=abs(a[i]-a[i+1]);
		}
		ans=cnt-abs(num);
		if(ans==2*k&&end==0)
		{
			end=1;
			for(j=1;j<=n*2;j++)
			{
				printf("%I64d ",a[j]);
			}
			return;
		}
	}
	for(i=1;i<=2*n;i++)
	{
		if(book[i]==0)
		{
			a[step]=i;
			book[i]=1;
			dfs(step+1);
			book[i]=0;
		}
	}
	return ;
}
int main()
{
	scanf("%I64d%I64d",&n,&k);
	dfs(1);
	return 0;
}
