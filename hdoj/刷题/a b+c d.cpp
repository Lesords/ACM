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
		nn=gcd(b,d);//������� 
		ans2=b*d/nn;//��С������ 
		ans1=a*(ans2/b)+c*(ans2/d);//��С���������Է�ĸ 
		if(gcd(ans1,ans2)!=1) 
		printf("%d %d\n",ans1/gcd(ans1,ans2),ans2/gcd(ans1,ans2));
		else
		printf("%d %d\n",ans1,ans2);
	}
	return 0;
}
