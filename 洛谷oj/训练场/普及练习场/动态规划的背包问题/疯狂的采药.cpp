#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;
const int MAXN = 1e4+5;
ll tim[MAXN],val[MAXN],dp[MAXN*10];//数组开小了！！！
//dp[i] 表示i时间内可以采到的最大价值的草药
int main() {
	int n,m;
	cin>>n>>m;
	for(int i = 1;i <= m;i++) cin>>tim[i]>>val[i];
	for(int i = 1;i <= m;i++) {
		for(int j = tim[i];j <= n;j++) {//升序遍历
			dp[j] = max(dp[j],dp[j-tim[i]]+val[i]);
		}//因为可以多次选择该草药
	}
	cout<<dp[n];
	return 0;
}
