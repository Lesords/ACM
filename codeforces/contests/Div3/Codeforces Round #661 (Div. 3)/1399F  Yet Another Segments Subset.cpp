#include<iostream>//ac
#include<cstdio>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;

//题意：计算可以包含的 最多数量的区间，使区间互不相交，但是可以包含或重叠
//题解：区间dp（记忆化搜索）
//状态：dp[l][r] 为区间[l, r]中可以包含的区间数量
//转移方程：dp[l][r] = max(dp[l][r], num+dp[l+1][r]) （也就是缩小左区间）
// dp[l][r] = max(dp[l][r], num + dp[l][v] + dp[v+1][r]) (v为以l为左区间时的左区间值)
// num为 [l, r] 区间的数量
//由于区间的值较大，所以可以先离散化！！！

const int MAXN = 6003;//左和右，所以有两倍！！！
int l[MAXN], r[MAXN];//记录左右区间
int dp[MAXN][MAXN];
vector<int> g[MAXN];
int cal(int l, int r) {
	//如果当前区间已经计算过，直接返回（记忆化）
	if(dp[l][r]!=-1) return dp[l][r];
	dp[l][r] = 0;									//初始化区间值为0
	if(l > r) return dp[l][r];						//如果区间不符合条件，直接返回
	int num = count(g[l].begin(), g[l].end(), r);	//计算 [l, r] 区间数量
	dp[l][r] = max(dp[l][r], num+cal(l+1, r));		//缩小左区间
	for(auto v:g[l]) {								//遍历所有存在 以l为左区间 的右区间
		if(v >= r) continue;						//等于r的已经算过了，所以都忽略
		//区间[l, v] + 区间[v+1, r] + 区间[l, r]
		dp[l][r] = max(dp[l][r], num + cal(l, v) + cal(v+1, r));
	}
	return dp[l][r];
}
int main() {
	fast;
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> all;
		for(int i = 1;i <= n;i++) {
			cin >> l[i] >> r[i];
			all.push_back(l[i]);
			all.push_back(r[i]);
		}
		//离散化
		sort(all.begin(), all.end());
		all.erase(unique(all.begin(), all.end()), all.end());
		for(int i = 1;i <= n;i++) {
			//修改为离散后的区间值
			l[i] = lower_bound(all.begin(), all.end(), l[i]) - all.begin();
			r[i] = lower_bound(all.begin(), all.end(), r[i]) - all.begin();
			g[l[i]].push_back(r[i]);//根据左边界来添加右边界值
		}
		int siz = all.size();
		for(int i = 0;i < siz;i++) {//初始化所有位置为-1
			for(int j = 0;j < siz;j++) dp[i][j] = -1;
		}
		cout << cal(0, siz-1) << "\n";//离散后，初始位置从0开始
		for(int i = 0;i < siz;i++) g[i].clear();//记得清空！！！
	}
	return 0;
}