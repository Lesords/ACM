// Problem: P3366 【模板】最小生成树
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3366
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// 
// Author：Lese
// Time：2021-09-18 15:09:47

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
#define LINF 0x3f3f3f3f3f3f3f3f
#define pii pair<int,int>
#define fi first
#define se second
#define eps 1e-6
using namespace std;
const int MOD = 1e9+7;
const double pi = acos(double(-1));


#define INF 0x3f3f3f3f
const int MAXN = 5e3+5;
int a[MAXN][MAXN], d[MAXN], n, m, ans;					//a记录原图，d记录当前较短距离
bool v[MAXN];											//v记录当前点是否被选过
int prim(int u) {//u为起点
    int ans = 0;
    for(int i = 1;i <= n;i++) {							//记录所有从u开始的路径长度
    	d[i] = a[u][i];
    }
    memset(v, 0, sizeof v);
    v[u] = 1;
    for(int i = 1;i < n;i++) {
        int x = 0;										//x为距离较短的点编号
        for(int j = 1;j <= n;j++)
            if(!v[j] && (x == 0 || d[j] < d[x])) x = j;
        if(d[x]==INF) return -1;						//原图不连通
        v[x] = 1;
        ans += d[x];
        for(int y = 1;y <= n;y++)
            if(!v[y]) d[y] = min(d[y], a[x][y]);		//更新对应距离
    }
    return ans;
}
int main() {
    cin >> n >> m;
    memset(a, 0x3f, sizeof a);
    for(int i = 1;i <= n;i++) a[i][i] = 0;				//自环距离为0
    for(int i = 1;i <= m;i++) {
        int x,y,z;
        scanf("%d%d%d", &x, &y, &z);
        a[y][x] = a[x][y] = min(a[x][y], z);			//更新为较小值
    }   
    int ans = prim(1);
    if(ans==-1) cout<<"orz";							//不连通
    else cout<<ans;
    return 0;
}