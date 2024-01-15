#include<stdio.h>
#include<string.h>
char a[105];
int main()
{
	int book,flag;
	scanf("%s",a);
	book=a[0];
	flag=1;
	for(int i=1;i<strlen(a);i++) {
		if(a[i]==book) flag++;
		else {
			book=a[i];
			flag=1;
		}
		if(flag>=7) break; 
	}
	if(flag>=7)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
} 
