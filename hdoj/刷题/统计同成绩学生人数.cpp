#include<stdio.h>
#include<string.h>
int a[105],cnt,ans,book[105];
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF) {
		ans=0;
		memset(a,0,sizeof(a));
		memset(book,0,sizeof(book));
		if(n==0) break;
		for(int i=1;i<=n;i++) {
			scanf("%d",&a[i]);
			book[a[i]]++;
		}
		scanf("%d",&cnt);
		printf("%d\n",book[cnt]);
	}
	return 0;
}
