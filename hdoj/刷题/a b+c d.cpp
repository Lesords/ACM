#include<stdio.h>
int gcd(int a,int b) {
	int r,t;
	if(a<b) {
		t=a;
		a=b;
		b=t;
	}
	while((r=a%b)!=0) {
		a=b;
		b=r;
	}
	return b;
}
int main() {
	int n,nn;
	int ans1,ans2,a,b,c,d;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d%d%d%d",&a,&b,&c,&d);
		nn=gcd(b,d);//最大公因数 
		ans2=b*d/nn;//最小公倍数 
		ans1=a*(ans2/b)+c*(ans2/d);//最小公倍数除以分母 
		if(gcd(ans1,ans2)!=1) 
		printf("%d %d\n",ans1/gcd(ans1,ans2),ans2/gcd(ans1,ans2));
		else
		printf("%d %d\n",ans1,ans2);
	}
	return 0;
}
