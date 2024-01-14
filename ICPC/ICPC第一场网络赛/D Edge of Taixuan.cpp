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

//题解：线段树
//先统计所有边的总和情况
//然后利用线段树来记录区间满足条件的最小值（边权倒序修改即为最小值）
//线段树每个点中记录的是 连接该位置所需要的最小值
//最后用总和 - 线段树总值即为最后结果！！！

const int MAXN = 1e5+5;
const int MOD = 1e9+7;
const double pi = acos(double(-1));
struct edge{
	int l, r;
	ll w;
	friend bool operator < (edge a,edge b) {
		return a.w > b.w;
	}
}a[MAXN];
struct node{
	int l, r, id;
	ll val;
}tree[MAXN<<2];
int n, m;
void build(int rt, int l, int r) {
	tree[rt].l = l, tree[rt].r = r;
	tree[rt].val = tree[rt].id = 0;
	if(l==r) return;
	int mid = (l+r)>>1;
	build(lson, l, mid);
	build(rson, mid+1, r);
}
void update(int rt, int l, int r, int id, int val) {
	int L = tree[rt].l;
	int R = tree[rt].r;
	if(l <= L && R <= r) {
		tree[rt].id = id;
		tree[rt].val = val;
		return ;
	}
	if(tree[rt].id) {//下传标记（因为此时更新[l, r]会分割原来的区间）
		tree[lson].id = tree[rson].id = tree[rt].id;
		tree[lson].val = tree[rson].val = tree[rt].val;
		tree[rt].id = tree[rt].val = 0;
	}
	int mid = (L+R)>>1;
	if(l <= mid) update(lson, l, r, id, val);
	if(r > mid) update(rson, l, r, id, val);
};
ll query(int rt, int l, int r) {
	int L = tree[rt].l;
	int R = tree[rt].r;
	if(tree[rt].id) {//节点有权值才需要返回结果
		return (R-L+1) *1ll * tree[rt].val;
	}
	if(L==R) return 0;
	return query(lson, l, r) + query(rson, l, r);
}
bool cmp(edge a, edge b) {
	if(a.l == b.l) return a.r < b.r;
	return a.l < b.l;
}
bool judge() {
	sort(a+1, a+m+1, cmp);
	int r = 1;
	for(int i = 1;i <= m;i++) {
		if(a[i].l > r) return true;
		r = max(r, a[i].r);
	}
	//判断的是最大的r而不是最后一个r（可能前面的r值更大）！！！
	if(r < n) return true;
	return false;
}
int main() {
	fast;
    int t;
    cin>>t;
    for(int cas = 1;cas <= t;cas++) {
    	if(cas!=1) cout<<"\n";
    	cout<<"Case #"<<cas<<": ";
    	cin>>n>>m;
    	build(1, 1, n);//初始化线段树
    	ll sum = 0;//记录总和
    	for(int i = 1;i <= m;i++) {
    		cin>>a[i].l>>a[i].r>>a[i].w;
    		sum += (a[i].r-a[i].l) *1ll* (a[i].r-a[i].l+1) /2 * a[i].w;
    	}
    	if(judge()) {//先判断是否覆盖所有位置
    		cout<<"Gotta prepare a lesson";
    		continue;
    	}
    	sort(a+1, a+m+1);//按照边权值从大到小排序
    	for(int i = 1;i <= m;i++) {
    		update(1, a[i].l+1, a[i].r, a[i].l, a[i].w);
    	}
    	cout<<sum - query(1, 1, n);
    }
    return 0;
}
