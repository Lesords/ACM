#include<iostream>//ac
#include<algorithm>
using namespace std;
const int MAXN = 1e5+5;
struct node{
	int x,y;//内存和速度
	friend bool operator < (node a,node b) {
		if(a.x!=b.x) return a.x < b.x;//先按内存排序
		return a.y < b.y;//后按速度排序
	}
}a[MAXN];
int suf[MAXN];//后缀 最大速度
int main() {
	int n,ans = 0;
	cin>>n;
	for(int i = 1;i <= n;i++) {
		cin>>a[i].x>>a[i].y;
	}
	sort(a+1,a+n+1);
	suf[n] = a[n].y;//最后一个速度需初始化
	for(int i = n-1;i >= 1;i--) {
		suf[i] = max(suf[i+1],a[i].y);//更新后缀最大速度
	}
	for(int i = 1;i < n;i++) {
		//只需要判断 i+1 的后缀最大速度是否大于等于当前值即可
		//应为内存已经排好序了
		if(suf[i+1]>=a[i].y) ans++;
	}
	cout<<ans;
	return 0;
}
