#include<stdio.h>
int n,flag;
int a[]={4,7,44,47,74,77,447,444,474,477,744,747,774,777};
int main()
{
	int l;
	scanf("%d",&n);
	for(int i=0;i<14;i++) {
		if(n%a[i]==0) {
			flag=1;
			break;
		}
		if(n<a[i]) break;
	}
	if(flag==1) printf("YES\n");
	else printf("NO\n");
	return 0;
} 
