//题意：计算从1到n的各种路径中，最大承载重量为多少
#include<iostream>//ac
#include<cstdio>//不能用cin(tle)
#include<cstring>//prim计算最大生成树(速度比dijkstra快)
#include<algorithm>//最大生成树中的最小权值边即为结果
#define INF 9999999
using namespace std;
int map[1005][1005],n,m;
int prim(int u) {
	int maxx = INF,lowc[1005],mst[1005];
	for(int i = 1;i <= n;i++) {//初始化
		lowc[i] = map[u][i];
		mst[i] = u;
	}
	mst[u] = -1;
	for(int i = 1;i < n;i++) {
		int v = -1,minn = 0;//v为当前点，minn为权值
		for(int j = 1;j <= n;j++) {
			if(mst[j]!=-1&&minn<lowc[j]) {//找承载大的路
				minn = lowc[j];
				v = j;
			}
		}
		if(v!=-1) {
			maxx = min(minn,maxx);//取最小权值边
			mst[v] = -1;//标记当前点
			if(v==n) return maxx;//此时1可以到达n
			for(int j = 1;j <= n;j++) {
				if(mst[j] != -1 && lowc[j]<map[v][j]) {
					mst[j] = v;
					lowc[j] = map[v][j];//取较大权值
				}
			}
		}
	}
	return maxx;
}
int main() {
	int t;
	scanf("%d",&t);
	for(int cas = 1;cas <= t;cas++) {
		scanf("%d%d",&n,&m);
		int u,v,w;
		memset(map,0,sizeof(map));//初始化最小值
		while(m--) {
			scanf("%d%d%d",&u,&v,&w);//取较大值
			map[u][v] = map[v][u] = max(w,map[v][u]);
		}
		cout<<"Scenario #"<<cas<<':'<<endl;
		cout<<prim(1)<<endl<<endl;//多输出一个空行
	}
	return 0;
}
