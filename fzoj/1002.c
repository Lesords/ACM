#include<stdio.h>
int main()
{
	double c,sum;//精度问题需要用double 
	int i;
	while(scanf("%lf",&c)&&c!=0)
	{
		sum=0;
		for(i=2;;i++)
		{
			sum+=1.0/(i*1.0);
			if(sum>=c)
			break;
		}
		printf("%d card(s)\n",i-1);
	}
	return 0;
}
