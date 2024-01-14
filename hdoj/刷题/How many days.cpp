#include<stdio.h>
int ans,cnt;
int main(){
	int m,k;
	while(scanf("%d%d",&m,&k)!=EOF) {
		cnt=0;
		ans=0;
		if(m==0&&k==0) break;
		while(m--) {
			cnt++;
			if(cnt==k) {
				cnt=0;
				m++;
			}
			ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
} 
