//���⣺�����1��n�ĸ���·���У�����������Ϊ����
#include<iostream>//ac
#include<cstdio>//������cin(tle)
#include<cstring>//prim�������������(�ٶȱ�dijkstra��)
#include<algorithm>//����������е���СȨֵ�߼�Ϊ���
#define INF 9999999
using namespace std;
int map[1005][1005],n,m;
int prim(int u) {
	int maxx = INF,lowc[1005],mst[1005];
	for(int i = 1;i <= n;i++) {//��ʼ��
		lowc[i] = map[u][i];
		mst[i] = u;
	}
	mst[u] = -1;
	for(int i = 1;i < n;i++) {
		int v = -1,minn = 0;//vΪ��ǰ�㣬minnΪȨֵ
		for(int j = 1;j <= n;j++) {
			if(mst[j]!=-1&&minn<lowc[j]) {//�ҳ��ش��·
				minn = lowc[j];
				v = j;
			}
		}
		if(v!=-1) {
			maxx = min(minn,maxx);//ȡ��СȨֵ��
			mst[v] = -1;//��ǵ�ǰ��
			if(v==n) return maxx;//��ʱ1���Ե���n
			for(int j = 1;j <= n;j++) {
				if(mst[j] != -1 && lowc[j]<map[v][j]) {
					mst[j] = v;
					lowc[j] = map[v][j];//ȡ�ϴ�Ȩֵ
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
		memset(map,0,sizeof(map));//��ʼ����Сֵ
		while(m--) {
			scanf("%d%d%d",&u,&v,&w);//ȡ�ϴ�ֵ
			map[u][v] = map[v][u] = max(w,map[v][u]);
		}
		cout<<"Scenario #"<<cas<<':'<<endl;
		cout<<prim(1)<<endl<<endl;//�����һ������
	}
	return 0;
}
