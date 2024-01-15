#include<stdio.h>
int a[111];
int main()
{
	int n,k,ans=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
	}
	if(a[k]==0) {
		for(int i=k;i>=1;i--) {
			if(a[i]!=0) {
				ans=i;
				break;
			}
			else continue;
		}
	}
	else {
		ans=k;
		for(int i=k+1;i<=n;i++) {
			if(a[i]>=a[k]&&a[i]!=0)
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
