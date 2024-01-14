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
	if(x==y) return 0;//�Ѿ��ϲ�����Ҫ�� 
	else {
		dis[y]=x;
		return 1;//δ�ϲ���Ҫ�� 
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
		for(int i=1;i<=n+1;i++) dis[i]=i; //�ϲ�����������һλ�����1 
		for(int i=1;i<=m;i++) {
			cin>>l>>r;
			cnt+=merge(l,r+1);//�ϲ�Կ���п���ת�������� 
		}
		cout<<poww(26,n-cnt)<<endl;//(n-cnt) ��ʾ�ܳ��ȼ�ȥ�ϲ�����ĳ��� 
	}
	return 0;
} 
