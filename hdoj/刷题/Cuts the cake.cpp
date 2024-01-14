#include<stdio.h>
#include<math.h>
int main()
{
	double n;
	while(scanf("%lf",&n)!=EOF) {
		if(n==0) break;
		printf("%.3lf %.3lf\n",sqrt(n*n/3),sqrt(2*n*n/3));
	}
	return 0;
} 
