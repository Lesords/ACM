// Problem: F. Red-Black Number
// Contest: Codeforces - Codeforces Round #748 (Div. 3)
// URL: https://codeforces.ml/contest/1593/problem/F
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Author：Lese
// Time：2021-10-17 10:28:04

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

//题解：记忆化搜索
//状态为：dp[i][j][k][l]表示已经选了i个，其中%A的值为j，%B的值为k，红色的选了l
//因为根据总数和红色个数可以推出黑色个数，所以可以忽略黑色个数这一维

const int MAXN = 50;
const int MOD = 1e9+7;
const double pi = acos(double(-1));
int n, A, B;
int a[MAXN], dis, dp[MAXN][MAXN][MAXN][MAXN];
char tmp[MAXN], ans[MAXN];
//pos为当前已经匹配的位置，moda为模A后的值，modb为模B后的值，cnta为红色的选择数量
void dfs(int pos, int moda, int modb, int cnta) {
	if(dp[pos][moda][modb][cnta]!=-1) return;
	dp[pos][moda][modb][cnta] = 1;
	if(pos==n) {
		if(!moda&&!modb&&abs(n - 2*cnta) < dis&&cnta>0&&cnta<n) {
			dis = abs(n-2*cnta);
			for(int i = 1;i <= n;i++) ans[i] = tmp[i];
		}
		return;
	}
	int val = a[pos+1];
	tmp[pos+1] = 'R';
	dfs(pos+1, (moda*10+val)%A, modb, cnta+1);
	tmp[pos+1] = 'B';
	dfs(pos+1, moda, (modb*10+val)%B, cnta);
}
int main() {
    int t;
    cin>>t;
    while(t--) {
    	cin >> n >> A >> B;
    	for(int i = 1;i <= n;i++) scanf("%01d", &a[i]);
    	memset(dp, -1, sizeof(dp));
    	dis = INF;
    	dfs(0, 0, 0, 0);
    	if(dis==INF) cout << "-1\n";
    	else {
    		for(int i = 1;i <= n;i++) cout << ans[i];
    		cout << "\n";
    	}
    }
    return 0;
}
