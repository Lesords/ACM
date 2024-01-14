// Problem: Average distance
// Contest: HDOJ
// URL: http://acm.hdu.edu.cn/showproblem.php?pid=2376
// Memory Limit: 32 MB
// Time Limit: 1000 ms
// 
// Author：Lese
// Time：2021-10-25 12:35:50

#include<iostream>//ac
#include<cstring>
#include<cstdlib>
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
#define LINF 0x3f3f3f3f3f3f3f3f
#define pii pair<int,int>
#define fi first
#define se second
#define eps 1e-6
#define lson rt<<1
#define rson rt<<1|1
using namespace std;

//题意：计算一棵树的所有 点对的距离和 除 所有点对的数量的结果
//题解：计算每个边对结果的贡献值（对距离和的贡献），然后除对应的路径数即可
//每个边的贡献为：左右两边点数的乘积（表示左右点会经过当前边）
//由于是无根树，所以令0为根，从0开始遍历计算对应子树的节点数量
//若某个儿子节点的子树数量为val，那么 指向儿子节点的边 贡献次数为 (n-val)*val
//并且根据等差求和公式可得路径数量为 n*(n-1)

const int MAXN = 1e4+5;
const int MOD = 1e9+7;
const double pi = acos(double(-1));
struct node{
	int v;				//指向点
	ll w;				//对应边权值
};
vector<node> g[MAXN];	//存边
ll num[MAXN], ans;		//注意开longlong，两个都要！！！
int n;
void dfs(int now, int fa) {								//now为当前节点，fa为父节点
	num[now] = 1;										//初始化为1，为当前节点
	for(auto val:g[now]) {
		if(val.v==fa) continue;							//跳过父节点
		dfs(val.v, now);
		ans += val.w * (num[val.v] * (n-num[val.v]));	//计算当前边的贡献值
		num[now] += num[val.v];							//累加now的子树节点数量
	}
}
int main() {
    int t;
    cin>>t;
    while(t--) {
    	cin >> n;
    	for(int i = 0;i < n;i++) g[i].clear();			//清空边
    	for(int i = 1;i < n;i++) {
    		int u, v, w;
    		cin >> u >> v >> w;
    		g[u].push_back({v, w});
    		g[v].push_back({u, w});
    	}
    	ans = 0;										//初始化结果为0
    	dfs(0, -1);
    	// 路径数为 n*(n-1)/2 （等差求和公式）
    	printf("%.6f\n", (ans*1.0)/(n*1.0*(n-1)/2));
    }
    return 0;
}
