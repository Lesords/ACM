#include<iostream>//ac  前缀和
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;
int sum[3005],tmp;
int main() {
	int n,m,ans = INF;//初始化为INF
	cin>>n>>m;
	for(int i = 1;i <= n;i++) cin>>tmp,sum[i] = sum[i-1]+tmp;
	for(int i = m;i <= n;i++) {//从第m为开始遍历
		ans = min(ans,sum[i]-sum[i-m]);
	}//连续m个数的和可以看成是区间长度为m的和
	//那么可以用前缀和来遍历所有的m长区间和，取最小值
	cout<<ans;
	return 0;
}
