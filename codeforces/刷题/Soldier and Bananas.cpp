#include<stdio.h>
int k,n,w,ans;
int main()
{
	scanf("%d%d%d",&k,&n,&w);
	ans=k*((1+w)/2.0*w);
	if(n>=ans)
		printf("0\n");
	else
		printf("%d\n",ans-n);
	return 0;
}
