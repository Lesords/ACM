#include<iostream>//ac
#include<string>//string名.substr(起点,长度)
#include<algorithm>
#define ll long long
using namespace std;
const int MAXN = 3e5 + 5;
ll dp[MAXN];//dp[i]表示第i位的总得分
int main() {
	int n,a,b,c;
	string s;
	cin>>n>>a>>b>>c>>s;
	for(int i = 0;i < n;i++) {
		if(i>0) dp[i] = dp[i-1];//防止i出现负数
		//顺序不重要
		//往前推n个字符，若满足情况，则更新dp值为较大值
		if(i>=3&&s.substr(i-3,4)=="nico")
			dp[i] = max(dp[i],dp[i-3]+a);
		if(i>=5&&s.substr(i-5,6)=="niconi")
			dp[i] = max(dp[i],dp[i-5]+b);
		if(i>=9&&s.substr(i-9,10)=="niconiconi")
			dp[i] = max(dp[i],dp[i-9]+c);
	}
	cout<<dp[n-1]<<endl;
	return 0;
}
