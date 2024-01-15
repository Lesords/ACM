#include<iostream>//ac
#include<algorithm>
using namespace std;
int a[105],b[105],dp[1005];
//a数组保存时间，b数组为价值
//dp[i] 表示i时间内能采到的最大价值
int main() {
	int T,M;
	cin>>T>>M;
	for(int i = 1;i <= M;i++) cin>>a[i]>>b[i];
	for(int i = 1;i <= M;i++) {
		for(int j = T;j >= a[i];j--) {
			//目标容量T - 截止容量
			dp[j] = max(dp[j],dp[j-a[i]]+b[i]);
		}//要么采，要么不采，取大值
	}
	cout<<dp[T]<<endl;
	return 0;
}
