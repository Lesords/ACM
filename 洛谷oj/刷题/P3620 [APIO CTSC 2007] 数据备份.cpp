// Problem: P3620 [APIO/CTSC 2007] 数据备份
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3620
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Author：Lese
// Time：2021-09-10 10:49:07

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

//题解：反悔贪心
//对应本题而言，就是说，选了一个值之后，将当前值替换成 不选当前位置而选其他两个位置 的值
//由于本题需要计算最短的距离和，那么所有的距离和最优的选择肯定是相邻的两个办公楼
//所以可以记录所有办公楼之间的距离（共n-1个）
//将距离放入一个优先队列中（小顶堆，优先选择距离小的）
//每次选择完一个位置之后，需要标记左右两个位置（因为左右两个位置不能选，与当前位置有交集）
//因为当前位置对应的是两个办公楼，而左右两个位置刚好都与其中一个办公楼相连！！！
//然后需要修改当前位置的值为 左右两个位置值 - 当前位置值
//接着把当前位置再放入队列中，直到选择了k个位置
//记得 修改当前位置 之后，需要更新左右位置的值！！！

const int MAXN = 1e5+5;
const int MOD = 1e9+7;
const double pi = acos(double(-1));
struct node{
	int l,r;
}a[MAXN];
struct dot{
	int val,pos;
	friend bool operator < (dot a,dot b) {
		return a.val > b.val;//小顶堆，优先小值
	}
};
int dis[MAXN],vis[MAXN];//dis记录距离，vis记录对应位置是否可选
void del(int pos) {//删除pos点，需要更新左右两边的位置
	a[pos].l = a[a[pos].l].l;//左边的左边 是当前的左边
	a[pos].r = a[a[pos].r].r;//右边的右边 是当前的右边
	a[a[pos].l].r = pos;//左边的右边 是当前
	a[a[pos].r].l = pos;//右边的左边 是当前
}
int main() {
	priority_queue<dot> q;
	int n,k,last;
	cin>>n>>k>>last;
	for(int i = 1;i < n;i++) {
		int tmp;
		cin>>tmp;
		dis[i] = tmp-last;//记录距离
		last = tmp;//更新上一个位置的值！！！
		a[i].l = i-1;//记录左右的位置
		a[i].r = i+1;
		q.push({dis[i], i});//当前位置放入队列中去
	}
	dis[0] = dis[n] = INF;//将边界设为INF（防止涉及边界情况，因为要取两边的值）
	ll ans = 0;
	for(int i = 1;i <= k;i++) {
		while(vis[q.top().pos]) q.pop();//先弹出所有不可选的位置
		dot tmp = q.top();
		q.pop();
		vis[a[tmp.pos].l] = vis[a[tmp.pos].r] = 1;//标记左右两边不可选
		//更新当前位置的值（删除当前位置+两边位置）
		dis[tmp.pos] = dis[a[tmp.pos].l]+dis[a[tmp.pos].r]-dis[tmp.pos];
		ans += tmp.val;//更新值
		q.push({dis[tmp.pos], tmp.pos});//将当前点继续放入队列中去
		del(tmp.pos);//删除当前位置，并且更新左右信息
	}
	cout<<ans;
    return 0;
}