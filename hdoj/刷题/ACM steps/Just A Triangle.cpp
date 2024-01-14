#include<stdio.h>
#include<algorithm>
using namespace std;
int main() {
	int n,a[4];
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d%d%d",&a[1],&a[2],&a[3]);
		sort(a+1,a+4);
		if(a[3]*a[3]==a[1]*a[1]+a[2]*a[2]) {
			printf("good\n");
			continue;
		}
		if(a[2]==a[1]||a[2]==a[3]) {
			printf("perfect\n");
			continue;
		}
		printf("just a triangle\n");
	}
	return 0;
} 
