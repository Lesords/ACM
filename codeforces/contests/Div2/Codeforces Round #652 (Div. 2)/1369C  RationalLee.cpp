#include<iostream>//ac
#include<cstdio>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;
const int MAXN = 2e5+10;
int a[MAXN],b[MAXN];
int main() {
	int t,n,m;
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--) {
		cin>>n>>m;
		ll ans = 0;//初始化为0
		for(int i = 1;i <= n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		for(int i = 1;i <= m;i++) cin>>b[i];
		sort(b+1,b+m+1);
		//礼物大小，和需要数量从小到大排序
		
		//只需要一个礼物的先分
		//然后以礼物数量最大优先的标准瓜分剩余礼物
		int l = 1, r = n,pos=m+1;//初始化pos必须大于m
		for(int i = 1;i <= m;i++) {
			//最大和最小都是a[r]
			if(b[i]==1) ans += 2*1LL*a[r--];
			else {//记录大于1个礼物数量的位置
				pos = i;break;
			}
		}
		//初始化pos，避免礼物重复计算
		for(int i = m;i >= pos;i--) {//计算多个的情况
			ans += a[r--]+a[l];//礼物堆中最大和最小的
			l += b[i]-1;//最小的需一起分出去(数量越多越好)
			//更新位置需要除去最大的一个
			//l更新的值必须为剩余礼物堆中最小值的位置
		}
		cout<<ans<<endl;
	}
	return 0;
}
