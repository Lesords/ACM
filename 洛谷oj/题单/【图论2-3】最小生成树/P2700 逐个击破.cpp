// Problem: P2700 逐个击破
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2700
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Author：Lese
// Time：2021-10-05 23:11:43

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
#define lson rt<<1
#define rson rt<<1|1
using namespace std;

//题解：最小生成树
//使删除的边总权值最小 可以转化为 使添加的边总权值最大
//结果 = 总边权值 - 添加的边总权值
//删除的边指的是 敌方军团之间的边
//添加的边指的是 两方有一方不为敌方军团的边
//那么可以将所有边根据边权值从大到小排序
//然后选择判断对应边的两端是否都与敌方军团相连，若都有，则跳过！！！
//可用并查集合并对应的点
//注意：连在一起后，需要判断是否有一方包含标记点，若有，需更新另一边

const int MAXN = 1e5+5;
const int MOD = 1e9+7;
const double pi = acos(double(-1));
struct node{
	int u, v, w;
	friend bool operator < (node a,node b){
		return a.w > b.w;//根据边权值从小到大排序
	}
}g[MAXN];
int n, k;
int a[MAXN], vis[MAXN], dis[MAXN];//a记录敌方军团信息，vis表示当前点是否与敌方军团相连
//dis记录祖先
int getf(int pos) {//路径压缩
	return dis[pos]==pos?pos:dis[pos] = getf(dis[pos]);
}
int main() {
	cin>>n>>k;
	for(int i = 1;i <= k;i++) {
		cin>>a[i];
		vis[a[i]] = 1;						//表示a[i]为敌方军团
	}
	ll sum = 0;//总边权值
	for(int i = 1;i < n;i++) {
		int u, v, w;
		cin>>u>>v>>w;
		sum += w;							//累加所有的边权值
		dis[i] = i;							//初始化祖先为本身
		g[i] = {u, v, w};					//存边
	}
	sort(g+1, g+n+1);						//根据边权值从大到小排序
	for(int i = 1;i < n;i++) {
		node tmp = g[i];
		int one = getf(tmp.u), two = getf(tmp.v);//获取两端对应的祖先节点编号
		if(vis[one]&&vis[two]) continue;	//若都与敌方军团相连，则跳过
		dis[one] = two;						//合并
		if(vis[one]==1) {//只要存在一方为敌方军团，则另外一方都要更新
			vis[two] = 1;
		}
		else if(vis[two]==1) {
			vis[one] = 1;
		}
		sum -= tmp.w;						//扣除对应的边权值
	}
	cout<<sum;
    return 0;
}