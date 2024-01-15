#include<stdio.h>
int n,a[100010],cnt=1,ans=1;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++) {
		if(i+1>n) break;
		if(a[i]<=a[i+1]) {
			cnt++;
			if(cnt>=ans) ans=cnt;
		}
		else {
			if(cnt>=ans) ans=cnt;
			cnt=1;
		}
	}
	printf("%d\n",ans);
	return 0;
}
