#include<stdio.h>
#include<string.h>
int book[10],r,y,cnt,ans,flag;
int main()
{
	scanf("%d",&y);
	for(int i=y+1;;i++) { 
		r=1000;
		flag=0;
		memset(book,0,sizeof(book));
		for(int j=1;j<=4;j++) {
			cnt=i/r%10;
			book[cnt]+=1;
			r/=10;
		}
		for(int j=0;j<=9;j++) {
			if(book[j]>=2) {
				flag=1;
				break;
			}
		}
		if(!flag) {
			ans=i;
			break;
		}
	}
	printf("%d\n",ans);
	return 0;
}
