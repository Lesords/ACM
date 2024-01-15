#include<iostream>//ac
#include<algorithm>
using namespace std;
const int MAXN = 2e4 + 5;
int dp[MAXN],a[MAXN];
//dp[i] 表示为i容量可以装最多的体积
int main() {
	int R,n;
	cin>>R>>n;
	for(int i = 1;i <= n;i++) cin>>a[i];
	for(int i = 1;i <= n;i++) {
		for(int j = R;j >= a[i];j--) {
			//目标容量 - 截止容量
			dp[j] = max(dp[j],dp[j-a[i]]+a[i]);
		}//要么装，要么不装，取大值
	}
	cout<<R-dp[R]<<endl;
	//求剩余最少，即为 容量R-装载最多的体积
	return 0;
}
