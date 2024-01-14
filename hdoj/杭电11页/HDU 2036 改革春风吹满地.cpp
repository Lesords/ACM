#include<iostream>//ac
#include<cstdio> 
#include<cmath>
using namespace std;
struct tri{
	int x,y;
}a[105];
double multi_cross(tri n,tri m) {//叉乘求面积
	//|a X b| = ax * by - ay * bx
	//注意：右边为i、j方向的向量长度
	return (n.x-a[1].x)*(m.y-a[1].y) - (n.y-a[1].y)*(m.x-a[1].x);
}
int main() {
	int n;
	double kk;
	while(cin>>n&&n) {
		for(int i = 1;i <= n;i++) cin>>a[i].x>>a[i].y;
		double ans = 0;
		for(int i = 2;i < n;i++) {
			ans += multi_cross(a[i],a[i+1]);
			//不需要绝对值，fabs函数精度过低
		}
		printf("%.1f\n",ans/2);//叉乘面积为正方形，除2即为三角形
	}
	return 0;
}
