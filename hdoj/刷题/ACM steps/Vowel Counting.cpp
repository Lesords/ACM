#include<stdio.h>
#include<string.h>
int n;
char a[55];
int main() {
	scanf("%d ",&n);
	for(int i=1;i<=n;i++) {
		memset(a,0,sizeof(a));
		gets(a);
		for(int j=0;j<strlen(a);j++) {
			if(a[j]=='a'||a[j]=='e'||a[j]=='i'
			||a[j]=='o'||a[j]=='u')
			a[j]-=32;
			else if(a[j]<=90&&a[j]!='A'&&a[j]!='E'
			&&a[j]!='I'&&a[j]!='O'&&a[j]!='U')
			a[j]+=32;
			printf("%c",a[j]);
		}
		printf("\n");
	}
	return 0;
} 
