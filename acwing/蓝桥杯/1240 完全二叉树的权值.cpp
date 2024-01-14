#include<iostream>//ac
#include<algorithm>
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;

//题解：前缀和计算每个深度的区间和，并更新最值

const int MAXN = 1e5+5;
ll a[MAXN],sum[MAXN];
int main() {
	int n;
	cin>>n;
	ll ans = -INF,deep = 0,cnt = 1;//ans初始化为负无穷！！！
	for(int i = 1;i <= n;i++) cin>>a[i],sum[i] = sum[i-1]+a[i];
	for(int i = 1;i <= n;i *= 2) {//遍历所有深度
		ll tmp;
		if(i*2-1>n) tmp = sum[n]-sum[i-1];//最后一层没满
		else tmp = sum[i*2-1]-sum[i-1];
		if(tmp>ans) {//当前深度的区间和更大时更新结果
			ans = tmp;
			deep = cnt;
		}
		cnt++;//当前深度++
	}
	cout<<deep<<endl;
	return 0;
}
