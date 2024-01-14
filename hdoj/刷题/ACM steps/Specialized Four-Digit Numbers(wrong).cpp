#include<stdio.h>
int sum(int a) {
	int ans=0,r=1;
	while(a!=0) {
		ans+=a%10;
		a/=10;
		//printf("%d %d %d\n",ans,a,r);
	}
	return ans;
}
int f1(int a) {
	int ans=0,cnt,r=1;
	while(a) {
		cnt=a%12;
		ans+=cnt*r;
		r*=10;
		a/=12;
	} 
	return ans;
}
int f2(int a) {
	int ans=0,cnt,r=1;
	while(a) {
		cnt=a%16;
		ans+=cnt*r;
		r*=10;
		a/=16;
	} 
	return ans;
}
int main() {
	int ans,cnt1,cnt2;
	for(int i=2992;i<=9999;i++) {
		ans=sum(sum(i));
		cnt1=sum(sum(f1(i)));
		cnt2=sum(sum(f2(i)));
		if(ans==cnt1&&cnt1==cnt2) printf("%d\n",i);
	}
	return 0;
}
