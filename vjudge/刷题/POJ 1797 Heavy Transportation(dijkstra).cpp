#include<iostream>//ac(dijkstra做法)
#include<cstdio>//计算1到n中的各个路段的最大承受重量
#include<cstring>//cin会慢
#include<algorithm>
#define INF 9999999
using namespace std;
int map[1005][1005],dis[1005],n,m,book[1005];
int dijkstra(int s) {
	for(int i = 1;i <= n;i++) {
		dis[i] = map[s][i];
	}
	memset(book,0,sizeof(book));
	book[s] = 1;
	for(int i = 1;i < n;i++) {
		int maxx = -1,u;
		for(int j = 1;j <= n;j++) {
			if(!book[j]&&dis[j]>maxx) {//寻找远路
				maxx = dis[u = j];
			}
		}
		if(maxx!=-1) {
			book[u] = 1;//标记已走过的点
			for(int j = 1;j <= n;j++) {
				if(!book[j]&&dis[j]< min(maxx,map[u][j])) {
					dis[j] = min(maxx,map[u][j]);
				}
				//dis[j]为直达的承载重量
				//maxx,map[u][j]为间接到达的各段路的承载重量
				/*
				如果直达的承载重量比间接到达的两个路的任一
				段路小的话，则需要更新dis数组
				*/
			}
		}
	}
	return dis[n];
}
int main() {
	int t;
	scanf("%d",&t);
	for(int cas = 1;cas <= t;cas++) {
		scanf("%d%d",&n,&m);
		int u,v,w;
		memset(map,0,sizeof(map));//初始化为0
		while(m--) {
			scanf("%d%d%d",&u,&v,&w);
			map[u][v] = map[v][u] = max(w,map[v][u]);
		}
		cout<<"Scenario #"<<cas<<':'<<endl;
		cout<<dijkstra(1)<<endl<<endl;
	}
	return 0;
}
