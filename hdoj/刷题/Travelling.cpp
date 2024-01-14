#include<iostream>//wa,Ë¼Â·´íÁË
#include<algorithm>
using namespace std;
int map[15][15],n,m;
int prim(int u) {
	int sum_mst = 0,lowc[15],mst[15];
	for(int i = 1;i <= n;i++) {
		lowc[i] = map[u][i];
		mst[i] = u;
	}
	mst[u] = -1;
	for(int i = 1;i < n;i++) {
		int v = -1,minn = 99999;
		for(int j = 1;j <= n;j++) {
			if(mst[j]!=-1&&minn>lowc[j]) {
				minn = lowc[j];
				v = j;
			}
		}
		if(v==-1) return -1;
		mst[v] = -1;
		sum_mst += lowc[v];
		for(int j = 1;j <= n;j++) {
			if(mst[j]!=-1&&lowc[j]>map[v][j]) {
				lowc[j] = map[v][j];
				mst[j] = v;
			}
		}
	}
	return sum_mst;
}
int main() {
	while(cin>>n>>m) {
		int u,v,w;
		for(int i = 1;i <= n;i++) 
			for(int j = 1;j <= n;j++)
				map[i][j] = map[j][i] = (i==j)?0:99999;
		for(int i = 1;i <= m;i++) {
			cin>>u>>v>>w;
			map[u][v] = map[v][u] = min(w,map[u][v]);
		}
		cout<<prim(1)<<endl;
	}
	return 0;
}
