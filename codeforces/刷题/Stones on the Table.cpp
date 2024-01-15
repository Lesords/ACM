#include<stdio.h>
char a[52],book;
int main()
{
	int n,ans=0;
	scanf("%d%*c",&n);
	for(int i=1;i<=n;i++) {
		scanf("%c",&a[i]);
		if(a[i]==book) {
			ans++;
		}
		else
		  book=a[i];
	}
	printf("%d\n",ans);
	return 0;
}
