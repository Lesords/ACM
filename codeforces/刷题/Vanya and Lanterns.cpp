#include<iostream>//ac
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 1e3 + 5;
double a[MAXN];
int main() {
	int n,l,now = 0;
	double ans;
	cin>>n>>l;
	for(int i = 1;i <= n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	ans = a[1]>(l-a[n])?a[1]:l-a[n];//首尾两个灯
	for(int i = 1;i <= n;i++) {//中间灯处理
		if((a[i]-now)/2>ans)
			ans = (a[i]-now)/2;
		now = a[i];
	}
	printf("%.10f\n",ans);
	return 0;
}
