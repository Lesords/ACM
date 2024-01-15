#include<stdio.h>
int a[100],sum;
void fibonacci() {
	a[0]=1,a[1]=1;
	for(int i=2;i<=45;i++) {
		a[i]=a[i-1]+a[i-2];
	}
	return;
}
int main()
{
	int k;
	fibonacci();
	scanf("%d",&k);
	for(int i=0;i<k;i++) {
		sum+=a[i];
	}
	printf("%d\n",sum);
	return 0;
}
