#include<stdio.h>
#include<string.h>
int flag; 
char a[105],b[105];
int main()
{
	scanf("%s%s",a,b);
	for(int i=0,j=strlen(a)-1;i<strlen(a);i++,j--) {
		if(a[i]!=b[j]) {
			flag=1;
			break;
		}
	}
	if(flag) printf("NO\n");
	else printf("YES\n");
	return 0;
} 
