#include<stdio.h>
int n,a[105],book[105];
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		book[a[i]]=i;
	}
	for(int i=1;i<=n;i++) {
		printf("%d ",book[i]);
	}
	return 0;
}
