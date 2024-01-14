#include<iostream>//ac
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<sstream>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<utility>
#include<bitset>
#include<algorithm>
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

//题解：树形DP
//分成三个状态考虑

const int MAXN = 1e5+5;
const int MOD = 998244353;
vector<int> g[MAXN];//存边
int n;
ll dp[MAXN][3];
void dfs(int now, int fa) {
	//初始化为1，因为操作都是乘！！！
	dp[now][0] = dp[now][1] = dp[now][2] = 1;
	for(int i = 0;i < g[now].size();i++) {
		int dot = g[now][i];
		if(dot==fa) continue;
		dfs(dot, now);
		//now点删除
		dp[now][0] = (dp[now][0] * (dp[dot][0]+dp[dot][1]))%MOD;
		//now点保留，但是儿子全删除
		dp[now][2] = (dp[now][2] * dp[dot][0])%MOD;
		//now点保留，并且至少存在一个儿子
		//将所有情况 - 没有儿子的情况 = 至少出现一个儿子的情况！！！
		dp[now][1] = (dp[now][1] * (dp[dot][0]+dp[dot][1]+dp[dot][2]))%MOD;
	}
	dp[now][1] = (dp[now][1] - dp[now][2])%MOD;//因为这里有减号，所以需要防止出现负数
}
int main() {
	fast;
    int t;
    cin>>t;
    while(t--) {
    	cin>>n;
    	for(int i = 1;i <= n;i++) g[i].clear();
    	for(int i = 1;i < n;i++) {
    		int u,v;
    		cin>>u>>v;
    		g[u].push_back(v);
    		g[v].push_back(u);
    	}
    	dfs(1, -1);//无根树，指定1为根（也可任意
    	//+MOD防止出现负数！！！
    	cout<<(dp[1][0]+dp[1][1]+MOD)%MOD<<"\n";
    }
    return 0;
}
