#include<stdio.h>
int a[1010],b[1010];
int main()
{
	int n,ans=0,book=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d%d",&a[i],&b[i]);
		//if(ans-a[i]+b[i]>ans)
		ans=ans-a[i]+b[i];
		if(ans>book)
		book=ans;
	}
	printf("%d\n",book);
	return 0;
}
