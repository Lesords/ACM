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
#include<bitset>
#include<algorithm>
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

//题意：判断路的权值大于p时，可以连通的城市数量
//题解：离线操作
//将所有查询按照权值从大到小排序
//然后在原图中建立最大生成树，并同时计算对应查询的结果
//当 当前选的边权值 小于查询的边权值，更新对应查询的结果，
//并且找到一个符合条件的查询位置！！！

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
struct node{
	int u, v, w;
	friend bool operator < (node a,node b) {
		return a.w > b.w;
	}	
}g[MAXN];
struct Que{
	int w,pos;
	friend bool operator < (Que a, Que b) {
		return a.w > b.w;
	}
}que[MAXN];
int dis[MAXN];//记录祖先
ll num[MAXN];//记录数量（并查集）
ll ans[MAXN];//记录最后 结果
int getf(int pos) {
	return dis[pos]==pos?pos:dis[pos] = getf(dis[pos]);	
}
int main() {
	fast;
    int t;
    cin>>t;
    while(t--) {
    	int n,m,q;
    	cin>>n>>m>>q;
    	//初始化，每个点的祖先为本身，数量为1
    	for(int i = 1;i <= n;i++) dis[i] = i,num[i] = 1;
    	for(int i = 1;i <= m;i++) {
    		int x,y,k;
    		cin>>x>>y>>k;
    		g[i] = {x,y,k};
    	}
    	sort(g+1, g+m+1);//将边从大到小排序
    	for(int i = 1;i <= q;i++) {
    		cin>>que[i].w;
    		que[i].pos = i;//记录对应查询的下标
    		ans[i] = 0;//初始化结果为0（如果查询的权值大于所有的边时，结果为0）
    	}
    	sort(que+1, que+q+1);//将查询按照权值从大到小排序
    	int pos = 1,minn = INF;//minn为当前生成树中最小的边权值，pos为当前查询的下标（排序后）
    	ll cnt = 0;//cnt为结果
    	for(int i = 1;i <= m;i++) {
    		node tmp = g[i];
    		if(getf(tmp.u)!=getf(tmp.v)) {//还未连边，直接合并
    			while(tmp.w<que[pos].w) {//如果当前边权小于查询权值（不满足条件），那么前面计算的结果满足条件
    				ans[que[pos].pos] = cnt;//根据查询下标记录值
    				pos++;//位置后移，找到一个满足条件的位置
    			}
    			minn = min(minn, tmp.w);//取最小值
    			tmp.u = getf(tmp.u);//找到对应祖先
    			tmp.v = getf(tmp.v);
    			cnt += num[tmp.u]*num[tmp.v];//此时多出来的联通数量=两个连通块数量的乘积
    			//将数量少的合并到数量大的里面去
    			if(num[tmp.u]>=num[tmp.v]) {
    				dis[tmp.v] = tmp.u;
    				num[tmp.u] += num[tmp.v];
    			}
    			else {
    				dis[tmp.u] = tmp.v;
    				num[tmp.v] += num[tmp.u];
    			}
    		}
    	}
    	for(int i = pos;i <= q;i++) {//如果还有查询还未遍历到
    		if(minn>=que[i].w) {//满足条件则更新答案，否则直接结束
    			ans[que[i].pos] = cnt;
    		}
    		else break;
    	}
    	for(int i = 1;i <= q;i++) {
    		cout<<ans[i]<<"\n";
    	}
    }
    return 0;
}
/*
1
3 2 4
1 2 11
2 3 4
4
5
11
12
output:
3
1
1
0
*/