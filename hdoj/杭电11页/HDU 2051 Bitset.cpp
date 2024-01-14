#include<stdio.h>
int f(int a) {
	int r=1,ans=0;
	while(a!=0) {
		if(a&1) ans+=r;
		r*=10;
		a>>=1;
	}
	return ans;
} 
int main(){
	int n;
	while(scanf("%d",&n)!=EOF) {
		printf("%d\n",f(n));
	}
	return 0;
}
