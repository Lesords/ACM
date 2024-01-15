#include<stdio.h>
#include<string.h>
char str[105];
int a,b,c,d,e,flag;
int main() {
	scanf("%s",str);
	for(int i=0;i<strlen(str);i++) {
		if(str[i]=='h'&&!b) {
			a=i;
		}
		if(str[i]=='e'&&!b) b=i;
		if(str[i]=='l'&&!c) {
			c=i;
			continue;
		}
		if(c&&str[i]=='l') d=i;
		if(str[i]=='o'&&!e) e=i; 
	}
	if(a<b&&b<c&&c<d&&d<e) printf("YES\n");
	else printf("NO\n");
	return 0;
}
