#include<stdio.h>
#include<string.h>
long long q,m,x,y[100010],d[100010],a,ans[100010];
char c;
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++) {
		x=1;
		memset(y,0,sizeof(y));
		memset(d,0,sizeof(d));
		memset(ans,0,sizeof(ans));
		scanf("%lld%lld",&q,&m);
		for(int j=1;j<=q;j++){
			scanf("%*c%c%lld",&c,&a);
			if(c=='M') {
				y[j]=a;
				x*=y[j];
				x%=m;
				ans[j]=x;
				//printf("%lld\n",x%m);
			}
			else {
				d[j]=a;
				x/=y[d[j]];
				x%=m;
				ans[j]=x;
				//printf("%lld\n",x%m);
			}
		}
		for(int j=1;j<=q;j++) {
			printf("%d\n",ans[j]);
		}
	}
	return 0;
} 
