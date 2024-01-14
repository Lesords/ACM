#include<iostream>//ac(dijkstra����)
#include<cstdio>//����1��n�еĸ���·�ε�����������
#include<cstring>//cin����
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
			if(!book[j]&&dis[j]>maxx) {//Ѱ��Զ·
				maxx = dis[u = j];
			}
		}
		if(maxx!=-1) {
			book[u] = 1;//������߹��ĵ�
			for(int j = 1;j <= n;j++) {
				if(!book[j]&&dis[j]< min(maxx,map[u][j])) {
					dis[j] = min(maxx,map[u][j]);
				}
				//dis[j]Ϊֱ��ĳ�������
				//maxx,map[u][j]Ϊ��ӵ���ĸ���·�ĳ�������
				/*
				���ֱ��ĳ��������ȼ�ӵ��������·����һ
				��·С�Ļ�������Ҫ����dis����
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
		memset(map,0,sizeof(map));//��ʼ��Ϊ0
		while(m--) {
			scanf("%d%d%d",&u,&v,&w);
			map[u][v] = map[v][u] = max(w,map[v][u]);
		}
		cout<<"Scenario #"<<cas<<':'<<endl;
		cout<<dijkstra(1)<<endl<<endl;
	}
	return 0;
}
