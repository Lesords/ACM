 #include<bits/stdc++.h>//ac
 using namespace std;
 const int maxn=1010;
 const double eps=1e-8;
 int n,m;
 double xs,ys,xt,yt; 
 int sgn (double x) {
     if (fabs(x)<eps) return 0;
     else if (x<0) return -1;
     else return 1;
 }
 double x[maxn],y[maxn];
 vector<pair<double,double> > p[maxn];
 //每个点和剩下所有点连成的直线与母线的交点
 
 //求两条直线的交点
 pair<double,double> jd (double x1,double y1,double x2,double y2,double x3,double y3,double x4,double y4) {
     if (x1==x2&&y1==y2) return make_pair(1e18,1e18);
     //(x1,y1),(x2,y2)组成的直线和(x3,y3),(x4,y4)组成的直线的交点
     
     //先计算对应斜率，把两点式转换为点斜式
     double k1=(x1==x2?1e18:(y1-y2)/(x1-x2));
     double k2=(x3==x4?1e18:(y3-y4)/(x3-x4));
     if (sgn(k1-k2)==0) return make_pair(1e18,1e18);
     //k1是1e18，k2不是，答案就是x1*k2+b2
     if (k1==1e18) {
         return make_pair(x1,x1*k2+y3-k2*x3);
     } 
     else if (k2==1e18) {
         return make_pair(x3, k1*x3+y1-k1*x1);
     }
     double b1=y1-k1*x1;
     double b2=y3-k2*x3;
     double x=(b2-b1)/(k1-k2);
     double y=k1*x+b1;
     return make_pair(x,y);
 }
 int cmp (pair<double,double> x,pair<double,double> y) {
 	//只需要左边离起点更近一点即可！！！
  	 return abs(x.first-xs) < abs(y.first-xs);
 } 
 int main () {
     scanf("%d%d",&n,&m);
     scanf("%lf%lf%lf%lf",&xs,&ys,&xt,&yt);
     for (int i=1;i<=n;i++) scanf("%lf%lf",x+i,y+i);
     for (int i=1;i<=n;i++) {
         for (int j=1;j<=n;j++) {
             if (i==j) continue;
             pair<double,double> it=jd(x[i],y[i],x[j],y[j],xs,ys,xt,yt); 
             if (it.first==1e18) continue;//没有交点
             if (sgn(it.first-min(xs,xt))<0||sgn(it.first-max(xs,xt))>0||sgn(it.second-min(ys,yt))<0||sgn(it.second-max(ys,yt))>0) continue;//交点在线段以外
             p[i].push_back(it);
         }
         sort(p[i].begin(), p[i].end(), cmp);//无需特判，直接和起点比较！！！
     }
     while (m--) {
         int h,t;
         scanf("%d%d",&h,&t);
         if (t>p[h].size()) {
             printf("-1\n");
             continue;
         }
         printf("%.10f %.10f\n",p[h][t-1].first,p[h][t-1].second);
     }
 }