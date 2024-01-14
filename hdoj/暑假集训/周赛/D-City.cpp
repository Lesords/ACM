#include<iostream>//ac
using namespace std;
int dis[10005],ans[100005],a[100005],b[100005];
int find(int x) {
	return dis[x]==x?x:dis[x]=find(dis[x]);
}
int main() {
	int n,m,x,y,num;
	ios::sync_with_stdio(false);
	while(cin>>n>>m) {
		num=n;
		for(int i=0;i<=n;i++) dis[i]=i;//从零开始初始化！！！ 
		for(int i=1;i<=m;i++) cin>>a[i]>>b[i];
		for(int i=m;i>=2;i--) {//m开始倒并查集！！！ 
			x=find(a[i]),y=find(b[i]);
			if(x!=y) num--,dis[x]=y;//独立的两部分合并,num-- 
			ans[i]=num;
		}
		//ans保存的是每次 倒合并 前状态的城市数
		//所以只需要遍历到2即可 
		ans[m+1]=n;//最后一个总是为n
		for(int i=2;i<=m+1;i++) cout<<ans[i]<<endl;
	}
	return 0;
} 
