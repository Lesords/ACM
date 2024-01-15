#include<stdio.h>
#include<string.h>
#include<ctype.h>
char a[105];
int lower1,lowern,book,upper;
int main()
{
	scanf("%s",a);
	for(int i=0;i<strlen(a);i++) {
		if(islower(a[i])&&!i) lower1=1;
		if(islower(a[i])&&i) lowern=1;
		if(islower(a[i])) upper=1;
	}
	if(lower1&&!lowern||!upper) {
		for(int i=0;i<strlen(a);i++)
		if(isupper(a[i])) a[i]+=32;
		else a[i]-=32;
	}
	printf("%s\n",a);
	return 0;
} 
