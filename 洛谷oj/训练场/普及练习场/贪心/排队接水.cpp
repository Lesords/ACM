#include<iostream>//ac
#include<cstdio>
#include<algorithm>
using namespace std;
struct node{
	int num,water;
	friend bool operator < (node a, node b) {
		return a.water < b.water;//从小到大排序
	}
}a[1005];
int main() {
	int n;
	cin>>n;
	for(int i = 1;i <= n;i++) cin>>a[i].water,a[i].num = i;
	sort(a+1,a+n+1);//第一人的排队时间为0
	double ans = 0,tmp = 0;//ans为总时间，tmp为每个人的排队时间
	for(int i = 1;i <= n;i++) {//每个人的时间相当于前缀和
		if(i!=1) cout<<' ',tmp += a[i-1].water,ans += tmp;
		cout<<a[i].num;
	}
	printf("\n%.2f",ans/n);
	return 0;
}
