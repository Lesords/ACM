#include<iostream>//ac
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 1005;
int val[MAXN],vol[MAXN],dp[MAXN];
//dp[i] 表示为容器为i时的最大值
int main() {
	int t,n,v;
	cin>>t;
	while(t--) {
		cin>>n>>v;
		memset(dp,0,sizeof(dp));//初始化
		for(int i = 1;i <= n;i++) cin>>val[i];
		for(int i = 1;i <= n;i++) cin>>vol[i];
		for(int i = 1;i <= n;i++) {
			for(int j = v;j >= vol[i];j--) {
				//vol[i]刚好够放截止
				dp[j] = max(dp[j],dp[j-vol[i]]+val[i]);
			}//要么当前不要，要么加上值，两者取较大值
		}
		cout<<dp[v]<<endl;
	}
	return 0;
}
