#include<stdio.h>
int n,a[105],b[105],ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d%d",&a[i],&b[i]);
		if(b[i]-a[i]>=2) ans++;
	}
	printf("%d\n",ans);
	return 0;
} 
