#include<iostream>//ac
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<utility>
#include<algorithm>
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

//题解：线性dp+滚动数组
//令 dp[i][j] 表示执行到第i个操作时，坏的电脑在j位置的最少不执行次数
//边界：所有位置先初始化为INF，然后令dp[0][k] = 0（初始点）
//转移方程：由于每次只有一个操作 (u,v) 表示u和v互换
//所以转移方程为： dp[i][u] = min(dp[i-1][v], dp[i-1][u]+1)   执行，不执行
//                 dp[i][u] = min(dp[i-1][u], dp[i-1][v]+1)
//目的状态：dp[n][i] 其中 1 <= i <= n
//由于每次转移只和上一个状态有关，所以可以用滚动数组把第一维优化掉，节省空间

const int MAXN = 1e5+5;
const int MOD = 1e9+7;
int dp[MAXN];//dp[i]: 表示执行到当前操作时，坏电脑在i位置的最少不执行次数
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        memset(dp, 0x3f,sizeof(dp));//初始化为INF
        int n,m,k;
        scanf("%d%d%d", &n,&m,&k);
        dp[k] = 0;//起点k为0！！！
        while(m--) {
            int u,v;
            scanf("%d%d", &u,&v);
            int last_u = dp[u],last_v = dp[v];//利用两个变量来存储上一个状态的值！！！
            dp[u] = min(last_v, last_u+1);//执行  不执行
            dp[v] = min(last_u, last_v+1);
        }
        for(int i = 1;i <= n;i++) {
            if(i!=1) printf(" ");
            if(dp[i]==INF) printf("-1");//INF表示无法到达，则输出-1
            else printf("%d", dp[i]);
        }
        puts("");
    }
	return 0;
}
