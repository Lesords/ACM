#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;
const int MAXN = 32010;
struct node{
	ll s,e;
	friend bool operator < (node a,node b) {
		//终点从小到大排序，起点从大到小排序
		if(a.e!=b.e) return a.e < b.e;
		return a.s > b.s;
	}
}a[MAXN];
int main() {
	int n,ans = 1;
	ll l,r,last;//last为上一个切的位置
	cin>>n;
	for(int i = 1;i <= n;i++) {
		cin>>l>>r;//r是长度!!!
		a[i].s = l;
		a[i].e = l+r;
	}
	sort(a+1,a+1+n);
	last = a[1].e;//第一次切的一定在第一条的最后位置
	for(int i = 2;i <= n;i++) {
		
		//长条的起点没有东西，所以不能切的！！！
		//可以理解为切 长条前面 位置
		//起点的长条 前面位置为空 ！！！
		
		//不包含起点！！！
		if(last>a[i].s) continue;//可以切到，跳过
		//再次切当前条的最后一个位置
		last = a[i].e;ans++;
	}
	cout<<ans;
	return 0;
}
