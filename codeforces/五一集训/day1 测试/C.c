#include<stdio.h>
#include<string.h>
char a[1000000],b[1000000];
int main()
{
	int min=999,max=0,cnt,flag=0;
	long int ans,l1,l2,i,j;
	scanf("%s", a);
	scanf("%s", b);
	l1=strlen(a);
	l2=strlen(b);
	for(i=l1-1, j = l2 - 1;i>=0 && j >=0;i--,j--)//&&�ܹؼ���&&��һ��Ϊ�٣��پ�����ѭ�� 
	{
		if(a[i]!=b[j])
		{
			break;
		}
	}
	ans=i+j+2;
	printf("%ld",ans);
	return 0;
}
