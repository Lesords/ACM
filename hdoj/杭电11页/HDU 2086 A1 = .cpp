#include<iostream>//ac
#include<cstring>//ÊýÑ§¹éÄÉ·¨
#include<cstdio>
using namespace std;
double a[3010],c[3010];
int main() {
	int n;
	while(scanf("%d",&n)!=EOF) {
		double ans = 0;
		memset(a,0,sizeof(a));
		scanf("%lf%lf",&a[0],&a[n+1]);
		for(int i = 1;i <= n;i++) scanf("%lf",&c[i]);
		ans += a[0] * n + a[n+1];
		for(int i = n,j = 1;i>=1;i--,j++) {
			ans -= i * c[j] * 2;
		}
		printf("%.2f\n",ans/(n+1));
		//a[1]=((n*a[0]+a[n+1])-2*(n*c[1]+(n-1)*c[2]+```+2*c[n-1]+c[n]))/(n+1)
	}
	return 0;
}
