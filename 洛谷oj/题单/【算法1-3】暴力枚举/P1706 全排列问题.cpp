#include<cstdio>//ac
#include<algorithm>
using namespace std;
int a[11] = {0,1,2,3,4,5,6,7,8,9,10};
int main() {
	int n;
	scanf("%d",&n);
	do {
		for(int i = 1;i <= n;i++) {
			printf("%5d",a[i]);
		}
		printf("\n");
	} while(next_permutation(a+1,a+n+1));
	return 0;
}
