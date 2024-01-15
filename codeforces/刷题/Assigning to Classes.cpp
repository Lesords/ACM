#include<iostream>//ac
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 2e5 + 5;
int a[MAXN];
int main() {
	int t,n;
	scanf("%d",&t);//数据量过大，可用scanf
	while(t--) {
		scanf("%d",&n);
		for(int i = 1;i <= 2*n;i++) scanf("%d",a+i);
		sort(a+1,a+2*n+1);
		printf("%d\n",a[n+1]-a[n]);
		//要想两个班的中位数差距小，那么取中间两个数即可
	}
	return 0;
}
