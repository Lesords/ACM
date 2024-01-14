#include<iostream>
#include<cstring>
using namespace std;
int dis[10000002],cnt,MOD=1000000007;
int find(int x) {
	return dis[x]=dis[x]==x?x:find(dis[x]);
}
int merge(int x,int y) {
	x=find(x);
	y=find(y);
	if(x==y) return 0;//已经合并则不需要减 
	else {
		dis[y]=x;
		return 1;//未合并需要减 
	}
}
long long poww(long long a,long long b) {
	long long ans=1,base=a;
	while(b!=0) {
		if(b&1) ans=(ans*base)%MOD;
		base=(base*base)%MOD;
		b>>=1;
	}
	return ans;
}
int main() {
	int n,m;
	while(cin>>n>>m) {
		int l,r;
		cnt=0;
		for(int i=1;i<=n+1;i++) dis[i]=i; //合并操作往后移一位，则加1 
		for(int i=1;i<=m;i++) {
			cin>>l>>r;
			cnt+=merge(l,r+1);//合并钥匙中可以转动的区间 
		}
		cout<<poww(26,n-cnt)<<endl;//(n-cnt) 表示总长度减去合并区间的长度 
	}
	return 0;
} 
