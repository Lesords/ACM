#include<stdio.h>
#include<string.h>
#include<ctype.h>
char a[105];
int up,lw,flag;
int main()
{
	int i=0;
	while(scanf("%c",&a[i])&&a[i]!='\n') {
		if(isupper(a[i])) up++;
		if(islower(a[i])) lw++;
		i++;
	}
	if(lw>=up) flag=1;
	if(flag) {
		for(int i=0;i<strlen(a);i++) {
			if(isupper(a[i])) a[i]+=32;
		}
	}
	else {
		for(int i=0;i<strlen(a);i++) {
			if(islower(a[i])) a[i]-=32;
		}
	}
	printf("%s\n",a);
	return 0;
}
