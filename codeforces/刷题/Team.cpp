#include<stdio.h>
int a[5];
int main()
{
	int n,ans=0,flag;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		flag=0;
		for(int j=1;j<=3;j++) {
			scanf("%d",&a[j]);
			if(a[j]==1) flag++;
			if(flag>=2&&j==3) {
				ans++;
			}
		} 
	}
	printf("%d\n",ans); 
	return 0;
} 
