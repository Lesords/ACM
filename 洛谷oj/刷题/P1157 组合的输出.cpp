#include<iostream>//ac
#include<cstdio>
using namespace std;
int a[25],vis[25],n,r;
void dfs(int step) {//step表示当前的位置
	if(step==r) {//r个时
		for(int i = 1;i <= r;i++) {//共r个数，3个字宽
			printf("%3d",a[i]);
		}
		printf("\n");
	}
	//后面的数字都需要比前面的大
	for(int i = a[step]+1;i <= n;i++) {
		if(vis[i]) continue;//已访问
		a[step+1] = i;
		vis[i] = 1;//标记
		dfs(step+1);
		vis[i] = 0;//取消标记
	}
}
int main() {
	cin>>n>>r;
	dfs(0);//从0开始
	return 0;
}
