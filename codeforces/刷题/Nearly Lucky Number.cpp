#include<stdio.h>
char a;
int flag;
int main()
{
	while(scanf("%c",&a)&&a!='\n') {
		if(a=='4'||a=='7') flag++;
	}
	if(flag==4||flag==7) printf("YES\n");
	else printf("NO\n");
	return 0;
}
