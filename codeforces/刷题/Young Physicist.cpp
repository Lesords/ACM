#include<stdio.h>
int x[105],y[105],z[105],sumx,sumy,sumz,n;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d%d%d",&x[i],&y[i],&z[i]);
		sumx+=x[i];
		sumy+=y[i];
		sumz+=z[i];
	}
	if(sumx==0&&sumy==0&&sumz==0) printf("YES\n");
	else printf("NO\n");
	return 0;
} 
