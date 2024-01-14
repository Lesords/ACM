#include<stdio.h>
#include<string.h>
int dis[100010],flag=1;
int getf(int n) {
	return dis[n]=(dis[n]==n)?n:getf(dis[n]);
}
void merge(int n,int m) {
	int t1=getf(n);
	int t2=getf(m);
	if(t1!=t2) {
		dis[t2]=t1;
		return ;
	}
	else {
		flag=0;
		return ;
	}
}
int main() {
	int n,m,sum=0,cnt=0,ans=0;
	for(int i=1;i<=100010;i++) dis[i]=i;
	while(scanf("%d%d",&n,&m)!=EOF) {
		if(n==-1&&m==-1) break;
		if(n==0&&m==0) {
			if(flag) printf("Yes\n");
			else printf("No\n");
			flag=1;
			for(int i=1;i<=100010;i++) dis[i]=i;
		} 
		merge(n,m);
	}
	return 0;
} 
