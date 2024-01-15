#include<stdio.h>
char a[155][5];
int main()
{
	int n,x=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%s",a[i]);
		if(a[i][0]=='+'||a[i][2]=='+')
		x++;
		else
		x--;
	}
	printf("%d\n",x);
	return 0;
}
