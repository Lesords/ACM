#include<stdio.h>
#include<string.h>
char a[105][105];
int book[105];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%s",a[i]);
		if(strlen(a[i])>10)
		book[i]=1;
	}
	for(int i=1;i<=n;i++) {
		if(book[i]==1) {
			printf("%c",a[i][0]);
			printf("%d",strlen(a[i])-2);
			printf("%c\n",a[i][strlen(a[i])-1]);
		}
		else
		printf("%s\n",a[i]);
	}
	return 0;
}
