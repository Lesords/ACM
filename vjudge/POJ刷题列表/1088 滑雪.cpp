// Problem: 滑雪
// Contest: Virtual Judge - POJ
// URL: https://vjudge.net/problem/POJ-1088
// Memory Limit: 65 MB
// Time Limit: 1000 ms
// 
// Author：Lese
// Time：2021-10-15 10:44:24

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

//题解：线性dp
//将所有位置的值 从小到大 排序
//然后遍历每个位置，判断对应位置原来所在的点是否可以向周围扩散，可以则转移
//初始化状态每个位置的结果都为1

const int MAXN = 105;
const int MOD = 1e9+7;
const double pi = acos(double(-1));
struct node {
	int x, y, val;
	friend bool operator < (node a, node b) {
		return a.val < b.val;//从小到大排序
	}
}data[MAXN*MAXN];
int nextt[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};//四个方向
int dp[MAXN][MAXN], a[MAXN][MAXN];//dp[i][j]为(i, j)位置可以滑的长度，a为对应点的高度
int main() {
    int r, c;
    cin >> r >> c;
    int cnt = 0;							//记录对应数据
    for(int i = 1;i <= r;i++) {
    	for(int j = 1;j <= c;j++) {
    		int tmp;
    		cin >> tmp;
    		a[i][j] = tmp;
    		dp[i][j] = 1;					//初始化对应位置值为1
    		data[++cnt] = {i, j, tmp};		//记录对应 点坐标及值
    	}
    }
    sort(data+1, data+cnt+1);				//从小到大排序
    for(int i = 1;i <= cnt;i++) {			//遍历所有位置
    	int x = data[i].x;
    	int y = data[i].y;
    	int val = data[i].val;
    	for(int j = 0;j < 4;j++) {			//寻找四个方向
    		int tx = x + nextt[j][0];
    		int ty = y + nextt[j][1];
    		if(tx < 1 || tx > r || ty < 1 || ty > c) continue;//越界，跳过
    		if(a[tx][ty] > a[x][y]) {		//若指向点小于当前高度，则需要转移
    			dp[tx][ty] = max(dp[tx][ty], dp[x][y]+1);
    		}
    	}
    }
    int ans = 0;
    for(int i = 1;i <= r;i++) {
    	for(int j = 1;j <= c;j++) {
    		ans = max(ans, dp[i][j]);		//取最大值
    	}
    }
    cout << ans;
    return 0;
}
