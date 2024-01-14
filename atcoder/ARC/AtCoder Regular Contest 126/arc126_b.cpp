// Problem: B - Cross-free Matching
// Contest: AtCoder - AtCoder Regular Contest 126
// URL: https://atcoder.jp/contests/arc126/tasks/arc126_b
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Author：Lese
// Time：2021-09-19 21:02:40

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
#define LINF 0x3f3f3f3f3f3f3f3f
#define pii pair<int,int>
#define fi first
#define se second
#define eps 1e-6
using namespace std;

//题解：由于选择的线，不能相交
//要想满足不相交的条件，那么肯定下方的点需要升序，对应的上方的点也需要升序
//也就是每条线都需要一定的距离

//那么如果我们固定下方的位置（从小到大排序）
//对于上面的位置，只需要满足当前值小于后面的位置（也就是说需要升序）即可
//那么即可转换成 最长上升子序列 问题

//需要注意的是：因为每个点可能有多条边，那么固定下方点之后
//对于上方的位置可以从大到小排序（这样重复的边只会有一条有贡献）

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
const double pi = acos(double(-1));
struct node {
	int s, t;
	friend bool operator < (node a, node b) {
		if(a.s == b.s) return a.t > b.t;//下方重复，则上方按照从大到小
		return a.s < b.s;				//下方按照从小到大排序
	}
}a[MAXN];
int b[MAXN], dp[MAXN];//b记录排序后的上方点位置，dp[i]为长度为i的LIS的较小值
int main() {
	int n,m;
	cin>>n>>m;
	for(int i = 1;i <= m;i++) {
		cin>>a[i].s>>a[i].t;
	}
	sort(a+1, a+m+1);							//排序
	for(int i = 1;i <= m;i++) b[i] = a[i].t;
	int pos = 1;//pos即为LIS长度的后一位，则pos-1为LIS长度
	for(int i = 1;i <= m;i++) {
		if(pos==1) dp[pos++] = b[i];			//当前为空，则直接记录
		else {
			//否则查询第一个大于等于b[i]的位置
			int p = lower_bound(dp+1, dp+pos, b[i]) - dp;
			if(p==pos) {						//若没找到，直接在末尾添加
				dp[pos++] = b[i];
			}
			else dp[p] = b[i];					//否则更新对应位置的值
		}
	}
	cout<<pos-1<<"\n";
    return 0;
}
