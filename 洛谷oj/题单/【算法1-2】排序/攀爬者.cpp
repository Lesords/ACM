#include<iostream>//ac
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN = 5e4+5;
struct node{
	double x,y,z;
	friend bool operator < (node a,node b) {
		return a.z<b.z;//根据高度排序
	}
}a[MAXN];
double cal(int i) {//计算距离
	double A = a[i].x-a[i-1].x;
	double B = a[i].y-a[i-1].y;
	double C = a[i].z-a[i-1].z;
	return sqrt(A*A+B*B+C*C);
}
int main() {
	int n;
	double ans = 0;
	cin>>n;
	for(int i = 1;i <= n;i++) cin>>a[i].x>>a[i].y>>a[i].z;
	sort(a+1,a+n+1);
	for(int i = 2;i <= n;i++) ans += cal(i);
	printf("%.3f\n",ans);
	return 0;
}
