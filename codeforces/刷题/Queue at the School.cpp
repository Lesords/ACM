#include<stdio.h>
char a[105];
int main()
{
	int n,t;
	scanf("%d%d%*c%s",&n,&t,a);
	for(int j=1;j<=t;j++) {
		for(int i=0;i<n;) {
			if(i+1>=n) break;
			if(a[i]=='B'&&a[i+1]=='G') {
				int c;
				c=a[i];
				a[i]=a[i+1];
				a[i+1]=c;
				i+=2;
				continue;
			}
			i++;
		}
	}
	printf("%s\n",a);
	return 0;
} 
