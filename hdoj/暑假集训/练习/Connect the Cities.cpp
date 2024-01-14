#include<stdio.h>//ac 
#define INF 9999999
#define min(x,y) ((x<y)?x:y)
int map[505][505],n;
void prim(int u) {
    int  lowc[505],sum_mst=0,mst[505],flag=0;
    //数组开到105会wa 
    for(int i=1;i<=n;i++) {
        lowc[i]=map[u][i];
        mst[i]=u;
    }
    mst[u]=-1;
    for(int i=1;i<n;i++) {
        int minn=INF,v=-1;
        for(int j=1;j<=n;j++) {
            if(mst[j]!=-1&&minn>lowc[j]) {
                minn=lowc[j];
                v=j;
            }
        }
        if(minn==INF) {//没有路了
            flag=1;
            break;
        }
        if(v!=-1) {
            sum_mst+=lowc[v];
            mst[v]=-1;
            for(int j=1;j<=n;j++) {
                if(mst[j]!=-1&&lowc[j]>map[v][j]) {
                    lowc[j]=map[v][j];
                    mst[j]=v;
                }
            }
        }
    }
    if(flag) printf("-1\n");
    else printf("%d\n",sum_mst);
}
int main() {
    int t,m,g,u,v,w,r,a[505];
    scanf("%d",&t);
    for(int i=1;i<=t;i++) {
        scanf("%d%d%d",&n,&m,&g);
        //数组开太大会tle
        for(int j=0;j<505;j++) {
            for(int k=0;k<505;k++)
              map[j][k]=map[k][j]=(j==k)?0:INF;
        }
        for(int j=1;j<=m;j++) {
            scanf("%d%d%d",&u,&v,&w);
            map[u][v]=map[v][u]=min(w,map[u][v]);
        }
        for(int j=1;j<=g;j++) {
            scanf("%d",&r);
            scanf("%d",&a[1]);
            for(int k=2;k<=r;k++) {
                scanf("%d",&a[k]);
                map[a[1]][a[k]]=map[a[k]][a[1]]=0;
                //仍然互通的城市道路花费置零
            }
        }
        prim(1);
    }
    return 0;
}
