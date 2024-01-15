#include<iostream>//ac
using namespace std;
const int MAXN = 1e5+5;
int fa[MAXN];
int find(int u) {//寻找祖先
	return fa[u]==u?u:fa[u]=find(fa[u]);
}//路径压缩
int main() {
	int n,m,u,v,ans = 0;
	cin>>n>>m;
	for(int i = 1;i <= n;i++) fa[i] = i;//初始化
	for(int i = 1;i <= m;i++) {
		cin>>u>>v;
		fa[find(u)] = fa[find(v)];//合并祖先
	}
	for(int i = 1;i <= n;i++) if(fa[i]==i) ans++;
	cout<<ans-1;//去除一个公共祖先
	return 0;
}
