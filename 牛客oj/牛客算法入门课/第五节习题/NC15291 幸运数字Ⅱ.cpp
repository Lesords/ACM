#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;
const int MAXN = 3e3+5;
ll a[MAXN],ans,cnt = 0;
void dfs(ll val) {
	if(val>=4444444444) return;//大于数据范围
	a[++cnt] = val*10+4;
	a[++cnt] = val*10+7;
	dfs(val*10+4);
	dfs(val*10+7);
}
int main() {
	int l,r;
	dfs(0);//先dfs生成所有对应数字
	sort(a+1,a+1+cnt);//生成数字需排序一次
	cin>>l>>r;
	//找到第一个大于l的数字位置
	int start = lower_bound(a+1,a+1+cnt,l)-a;
	for(int i = l;i <= r;i++) {
		//判断选择位置是否大于i
		//大于则直接加，否则后移一位再加
		if(i<=a[start]) ans += a[start];
		else ans += a[++start];
	}
	cout<<ans;
	return 0;
}
