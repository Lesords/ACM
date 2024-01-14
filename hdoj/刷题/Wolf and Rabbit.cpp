#include<stdio.h>
int gcd(int a,int b) {
	return a%b==0?b:gcd(b,a%b);
}
int main(){
	int n,a,b;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d%d",&a,&b);
		if(gcd(a,b)!=1) printf("YES\n"); 
		else printf("NO\n");
	} 
	return 0;
}
