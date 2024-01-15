#include<stdio.h>
#include<string.h>
char a[105];
int main()
{
	int num=0;
	char x[]={'h','e','l','l','o'};
	scanf("%s",a);
	for(int i=0;i<strlen(a);i++) {
		if(a[i]==x[num]) num++;
	}
	if(num==5)printf("YES\n");
	else printf("NO\n");
	return 0;
} 
