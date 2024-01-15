#include<stdio.h>
#include<stdlib.h>
int a[7][7];
int main()
{
	int cntx,cnty;
	for(int i=1;i<=5;i++) {
		for(int j=1;j<=5;j++) {
			scanf("%d",&a[i][j]);
			if(a[i][j]==1) {
				cntx=i;
				cnty=j;
				break;
			}
		}
	}
	printf("%d\n",abs(cntx-3)+abs(cnty-3));
	return 0;
}
