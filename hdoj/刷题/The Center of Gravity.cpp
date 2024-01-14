#include<stdio.h>
int n;
double x1,x2,x3,y1,y2,y3,x,y;
int main() {
	while(scanf("%d",&n)!=EOF) {
		if(n==0) break;
		for(int i=1;i<=n;i++) {
			scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3);
			x=(x1+x2+x3)/3;
			y=(y1+y2+y3)/3;
			printf("%.1f %.1f\n",x,y);
		}
	}
	return 0;
}
