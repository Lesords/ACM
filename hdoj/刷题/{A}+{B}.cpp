#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int a[20010],n,m;
int *l,*k;
int main() {
	while(scanf("%d%d",&n,&m)!=EOF) {
		for(int i=1;i<=n;i++) {
			scanf("%d",&a[i]);
		}
		for(int i=n+1;i<=m+n;i++) {
			scanf("%d",&a[i]);
		}
		sort(a+1,a+m+n+1);
		k=a+1;
		l=unique(a+1,a+m+n+1);
		for(int *i=k;i<l;i++) {
			printf("%d",*i);
			if(i!=l-1) printf(" ");
			else printf("\n");
		}
	}
	return 0;
}
