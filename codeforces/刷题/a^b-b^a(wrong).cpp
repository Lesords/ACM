#include<stdio.h>
#include<math.h>
int main()
{
	long long a,b,ans1=1,ans2=1;
	scanf("%lld%lld",&a,&b);
	for(int i=1;i<=b;i++) {
		ans1*=a;
	} 
	for(int i=1;i<=a;i++) {
		ans2*=b;
	}
	printf("%d\n",ans1-ans2);
	return 0;
}
