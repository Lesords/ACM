#include<stdio.h>
#include<string.h>
#include<math.h>
int m,cnt[105];
double map[105][105];
double f(double x1,double y1,double x2,double y2) {
	double d1=(x1-x2)*(x1-x2);
	double d2=(y1-y2)*(y1-y2);
	//printf("%f\n",sqrt(d1+d2));
	return sqrt(d1+d2);
}
void prim(int u) {
	int mst[105];
	memset(cnt,0,sizeof(cnt));
	double lowc[105],sum_mst=0;
	for(int i=1;i<=m;i++) {
		lowc[i]=map[u][i];
		mst[i]=u;
	}
	mst[u]=-1;
	cnt[u]=1;
	for(int i=1;i<m;i++) {
		int v=-1; 
		double minn=99999;//double很关键 
		for(int j=1;j<=m;j++) {
			if(mst[j]!=-1&&lowc[j]<minn) {
				minn=lowc[j];
				v=j;
			}
		}
		if(v!=-1) {
			mst[v]=-1;
			cnt[v]=1;
			sum_mst+=lowc[v];
			for(int j=1;j<=m;j++) {
				if(mst[j]!=-1&&lowc[j]>map[v][j]) {
					lowc[j]=map[v][j];
					mst[j]=v;
				}
			}
		}
	}
	int flag=0;
	for(int i=1;i<=m;i++) {
		if(mst[i]!=-1) {
			flag=1;
			break;
		}
	}
	if(flag) printf("oh!\n");
	else printf("%.1f\n",sum_mst*100);
}
int main() {
	int n;
	double x[105],y[105];
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",&m);
		for(int j=1;j<=m;j++) {
			scanf("%lf%lf",&x[j],&y[j]);
		}
		for(int i=1;i<=m;i++) {
			for(int j=1;j<=m;j++)
			map[i][j]=map[j][i]=(i==j)?0:99999;
		}
		for(int i=1;i<=m;i++) {
			for(int j=1;j<=m;j++) {
				if(i==j) continue;
				double dis=f(x[i],y[i],x[j],y[j]);
				if(dis<=1000&&dis>=10)//'='很关键 
					map[i][j]=dis;
			}
		}
		prim(1);
	}
	return 0;
}
