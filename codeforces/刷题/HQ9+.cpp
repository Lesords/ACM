#include<stdio.h>
#include<string.h>
char a[105],book[]="HQ9";
int flag;
int main() {
	scanf("%s",a);
	for(int i=0;i<strlen(book);i++) {
		if(strchr(a,book[i])) {
			flag=1;
			break; 
		}
	}
	if(flag) printf("YES\n");
	else printf("NO\n");
	return 0;
}
