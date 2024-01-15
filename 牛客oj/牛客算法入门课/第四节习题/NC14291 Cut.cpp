#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;
const int MAXN = 1e5+5;
ll a[MAXN];
int main() {
	ll n,sum = 0,ans = 0;//爆int！！！
	cin>>n;
	for(int i = 1;i <= n;i++) cin>>a[i],sum+=a[i];
	sort(a+1,a+1+n);//先排序后求结果
	for(int i = 1;i < n;i++) {//最后一个不需要分了
		ans += sum;//结果++
		sum -= a[i];//sum分离掉a[i]
	}
	cout<<ans;
	return 0;
}
