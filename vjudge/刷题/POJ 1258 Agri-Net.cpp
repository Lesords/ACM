#include<iostream>//ac
using namespace std;
int n,map[105][105];
int prim(int u) {
	int sum_mst = 0,lowc[105],mst[105];
	for(int i = 1;i <= n;i++) {
		lowc[i] = map[u][i];
		mst[i] = u;
	}
	mst[u] = -1;
	for(int i = 1;i < n;i++) {
		int minn = 999999,v = -1;
		for(int j = 1;j <= n;j++) {//зЂвт-1
			if(mst[j]!=-1&&minn>lowc[j]) {
				minn = lowc[j];
				v = j;
			}
		}
		if(v!=-1) {
			sum_mst += lowc[v];
			mst[v] = -1;
			for(int j = 1;j <= n;j++) {
				if(mst[j]!=-1&&lowc[j]>map[v][j]) {
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
		for(int i = 1;i <= n;i++) {
			for(int j = 1;j <= n;j++)
			cin>>map[i][j];
		}
		cout<<prim(1)<<endl;
	}
	return 0;
} 
