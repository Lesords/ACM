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
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

//题解：思维+线段树
//由于每次添加的是lowbit，那么需要知道的是，加到最后会成为2的次幂
//然后再继续添加的话，其实值就是*2
//那么也就说每个区间，前面需要单点修改，但是后面可以直接整体*2
//所以，可以多添加一个标记flag，来表示是否可以整体*2
//然后再用一个lazy标记来记录*2的数量（更新时用快速幂计算）

//需要注意的是，最后成为的 2的次幂 会大于MOD，所以不用取模！！！

const int MAXN = 1e5+5;
const int MOD = 998244353;
struct node{
	int l,r;
	ll val;//开longlong！！！
	int lazy,flag;//lazy记录*2的数量，flag判断是否需要乘2
}tree[MAXN<<2];
int n;
ll a[MAXN];
int lowbit(int x) {
	return (x)&(-x);	
}
ll poww(ll a,ll b) {//计算a^b结果
	ll ans = 1;
	while(b) {
		if(b&1) ans = (ans*a)%MOD;
		a = (a*a)%MOD;
		b >>= 1;
	}	
	return ans%MOD;
}
void push_up(int rt) {//向上更新
	//更新区间和
	tree[rt].val = (tree[rt<<1].val + tree[rt<<1|1].val)%MOD;
	//判断区间是否可以整体 *2
	tree[rt].flag = (tree[rt<<1].flag & tree[rt<<1|1].flag);
}
//建树
void build(int rt,int l, int r) {
	tree[rt].l = l, tree[rt].r = r;
	tree[rt].flag = tree[rt].lazy = 0;
	if(l==r) {//叶子节点
		tree[rt].val = a[l];//记录值
		//若为2的次幂，则记录标记
		if(lowbit(a[l]) == a[l]) tree[rt].flag = 1;
		return;
	}
	int mid = (l+r)/2;
	build(rt<<1, l, mid);//分别计算左右子树
	build(rt<<1|1, mid+1, r);
	push_up(rt);//向上更新
}
//向下传递标记，rt为当前节点, [l, r] 为当前区间，mid为中间点
void push_down(int rt,int l,int mid,int r) {
	if(tree[rt].lazy) {
		//整体乘 tree[rt].lazy 次 2（直接快速幂）
		tree[rt<<1].val = (tree[rt<<1].val*1ll*poww(2, tree[rt].lazy))%MOD;
		tree[rt<<1|1].val = (tree[rt<<1|1].val*1ll*poww(2, tree[rt].lazy))%MOD;
		//传递标记
		tree[rt<<1].lazy += tree[rt].lazy;
		tree[rt<<1|1].lazy += tree[rt].lazy;
		tree[rt].lazy = 0;//标记清零
	}	
}
void update(int rt,int l,int r) {//更新[l,r]区间 + lowbit
	int L = tree[rt].l;
	int R = tree[rt].r;
	if(l<=L&&R<=r&&tree[rt].flag) {//如果当前节点满足整体*2
		tree[rt].val = (tree[rt].val*2)%MOD;
		tree[rt].lazy++;//添加标记
		return;
	}
	if(L==R) {//否则等到叶节点时，更新对应值
		tree[rt].val += lowbit(tree[rt].val);//直接添加lowbit（不用取模！！！）
		//如果为2的次幂，注意标记
		if(lowbit(tree[rt].val) == tree[rt].val) {
			tree[rt].flag = 1;
		}
		return;
	}
	int mid = (L+R)/2;
	push_down(rt, L, mid, R);//向下传递标记
	if(l<=mid) update(rt<<1, l, r);//分别更新左右子树（如果涉及的话）
	if(r>mid) update(rt<<1|1, l, r);
	push_up(rt);//向上更新
}
int query(int rt,int l,int r) {//查询[l, r]区间的值
	int L = tree[rt].l;
	int R = tree[rt].r;
	if(l<=L&&R<=r) {//直接返回整个区间的值
		return (tree[rt].val)%MOD;
	}
	ll ans = 0;
	int mid = (L+R)/2;
	push_down(rt, L, mid, R);//传递标记
	if(l<=mid) ans = (ans + query(rt<<1, l, r))%MOD;//分别累加左右子树的值（如果涉及的话）
	if(r>mid) ans = (ans+ query(rt<<1|1, l, r))%MOD;
	return ans%MOD;//返回结果
}
int main() {
	fast;
    int t;
    cin>>t;
    while(t--) {
    	cin>>n;
    	for(int i = 1;i <= n;i++) {
    		cin>>a[i];
    	}
    	build(1, 1, n);
    	int m;cin>>m;
    	for(int i = 1;i <= m;i++) {
    		int op, l, r;
    		cin>>op>>l>>r;
    		if(op==1) {
    			update(1, l, r);
    		}
    		else {
    			cout<<query(1, l, r)<<"\n";
    		}
    	}
    }
    return 0;
}
