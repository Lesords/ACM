#include<iostream>//ac
#include<algorithm>
using namespace std;
const int MAXN = 3e4 + 5;
int pri[30],w[30],dp[MAXN],p;
//dp[i] 表示为i元买到的物品的重要度之和
int main() {
	int n,m;
	cin>>n>>m;//无需二维，购买个数不为m！！！
	for(int i = 1;i <= m;i++) cin>>pri[i]>>p,w[i] = p*pri[i];
	for(int i = 1;i <= m;i++) {//遍历所有物品
		for(int j = n;j >= pri[i];j--) {//遍历各个价位
		    dp[j] = max(dp[j],dp[j-pri[i]]+w[i]);
		}//买或不买取大值，价格为price[i]，重要度为乘积
	}
	cout<<dp[n]<<endl;
	return 0;
}
