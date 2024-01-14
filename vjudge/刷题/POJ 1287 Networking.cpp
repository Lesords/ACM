#include<iostream>//ac
#include<algorithm>
using namespace std;
int n,m,map[55][55];
int prim(int u) {
	int sum_mst = 0,lowc[55],mst[55];
	for(int i = 1;i <= n;i++) {//预处理
		lowc[i] = map[u][i];
		mst[i] = u;
	}
	mst[u] = -1;
	for(int i = 1;i < n;i++) {
		int v = -1,minn = 999999;
		for(int j = 1;j <= n;j++) {//找较短路
			if(mst[j]!=-1&&minn>lowc[j]) {
				minn = lowc[j];
				v = j;
			}
		}
		if(v!=-1) {
			mst[v] = -1;
			sum_mst += lowc[v];
			for(int j = 1;j <= n;j++) {//更新lowc数组
				if(mst[j]!=-1&&lowc[j] > map[v][j]) {
					lowc[j] = map[v][j];
					mst[j] = v;
				}
			}
		}
	}
	return sum_mst;
}
int main() {
	while(cin>>n) {
		if(n==0) break;
		cin>>m;
		int u,v,w;
		for(int i = 1;i <= n;i++) {//预处理
			for(int j = 1;j <= n;j++)
				map[i][j] = map[j][i] = (i==j)?0:999999;
		}
		while(m--) {
			cin>>u>>v>>w;
			map[u][v] = map[v][u] = min(map[u][v],w);
		}
		cout<<prim(1)<<endl;
	}
	return 0;
} 
