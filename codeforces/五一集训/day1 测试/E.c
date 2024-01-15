#include<stdio.h>
long long a[1000000],book[1000000];
int main()
{
	long long i,n,m,t,v,x,y,q,sum=0;
	scanf("%I64d%I64d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%I64d",&a[i]);
	}
	while(scanf("%I64d",&t)!=EOF)
	{
		if(t==1)
		{
			scanf("%I64d%I64d",&v,&x);
			a[v]=x;
			book[v]=sum;//保存当前时候操作2所加入的数据 
		}
		else if(t==2)
		{
			scanf("%I64d",&y);
			sum+=y;
		}
		else
		{
			scanf("%I64d",&q);
			printf("%I64d\n",a[q]+sum-book[q]);
		}
	}
	return 0;
}
