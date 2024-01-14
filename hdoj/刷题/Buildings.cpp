#include<stdio.h>
int main() {
	int n,a,b,cnt,ans;
	scanf("%d",&n); 
	for(int i=1;i<=n;i++) {
		ans=0;
		scanf("%d%d",&a,&b);
		for(int j=1;j<=a;j++) {
			for(int k=1;k<=b;k++) {
				scanf("%d",&cnt);
				if(cnt) ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
} 
