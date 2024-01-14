#include<stdio.h>
#include<string.h>
unsigned long long mod;
struct cmd
{
	char num[22];
	unsigned long long size;
};
void init()
{
	int i;
	mod=1;
	for(i=1;i<=47;i++)
	{
		mod*=2;
	}
}
int main()
{
	struct cmd hh[5000];
	char a[20],num1[20],num2[20];
	int i=0,j,n1,n2; 
	init();
	while(scanf("%s",a)!=EOF)
	{
		if(strcmp(a,"def")==0)
		{
			scanf("%s%lld",hh[i].num,&hh[i].size);
			printf("%s = %lld\n",hh[i].num,hh[i].size);
			i++;
		}
		if(strcmp(a,"add")==0)
		{
			scanf("%s%s",num1,num2);
			for(j=0;j<5000;j++)
			{
				if(strcmp(hh[j].num,num1)==0)
				{n1=j;}
				if(strcmp(hh[j].num,num2)==0)
				{n2=j;}
			}
			hh[n1].size=(hh[n1].size+hh[n2].size)%mod;
			printf("%s = %lld\n",hh[n1].num,hh[n1].size);
		}
		if(strcmp(a,"sub")==0)
		{
			scanf("%s%s",num1,num2);
			for(j=0;j<5000;j++)
			{
				if(strcmp(hh[j].num,num1)==0)
				{n1=j;}
				if(strcmp(hh[j].num,num2)==0)
				{n2=j;}
			}
			hh[n1].size=(hh[n1].size-hh[n2].size+mod)%mod;
			printf("%s = %lld\n",hh[n1].num,hh[n1].size);
		}
		if(strcmp(a,"mul")==0)
		{
			scanf("%s%s",num1,num2);
			for(j=0;j<5000;j++)
			{
				if(strcmp(hh[j].num,num1)==0)
				{n1=j;}
				if(strcmp(hh[j].num,num2)==0)
				{n2=j;}
			}
			hh[n1].size=(hh[n1].size*hh[n2].size)%mod;
			printf("%s = %lld\n",hh[n1].num,hh[n1].size);
		}
		if(strcmp(a,"div")==0)
		{
			scanf("%s%s",num1,num2);
			for(j=0;j<5000;j++)
			{
				if(strcmp(hh[j].num,num1)==0)
				{n1=j;}
				if(strcmp(hh[j].num,num2)==0)
				{n2=j;}
			}
			hh[n1].size=hh[n1].size/hh[n2].size;
			printf("%s = %lld\n",hh[n1].num,hh[n1].size);
		}
		if(strcmp(a,"mod")==0)
		{
			scanf("%s%s",num1,num2);
			for(j=0;j<5000;j++)
			{
				if(strcmp(hh[j].num,num1)==0)
				{n1=j;}
				if(strcmp(hh[j].num,num2)==0)
				{n2=j;}
			}
			hh[n1].size=hh[n1].size%hh[n2].size;
			printf("%s = %lld\n",hh[n1].num,hh[n1].size);
		}
	}
	return 0;
}
