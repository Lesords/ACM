// Problem: CF438D The Child and Sequence
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF438D
// Memory Limit: 250 MB
// Time Limit: 4000 ms
// 
// Author：Lese
// Time：2021-09-28 23:59:49

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

//题解：势能线段树
//对于每个位置的值val来说，进行取模操作 %x 时
//如果 val 的值小于x，那么结果不变，也就说可以忽略这个操作
//否则，对于val来说，val%x 的结果肯定小于 val/2
//例如： 7%4 = 3, 5%4 = 1
//也就是说，其实每个值最多只需要操作logn次（n为val值）
//那么可以给每个节点取最大值，如果x大于区间最大值，那么当前区间无需修改
//否则逐个暴力修改
//注意：需要longlong！！！

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
const double pi = acos(double(-1));
struct node{
	int l, r;
	ll val, maxx;//val为区间和，maxx为区间最大值
}tree[MAXN<<2];
ll a[MAXN];
void push_up(int rt) {//向上更新值
	tree[rt].val = tree[lson].val + tree[rson].val;
	tree[rt].maxx = max(tree[lson].maxx, tree[rson].maxx);
}
//rt为当前节点，[l, r]为操作区间
void build(int rt, int l, int r) {				//初始化线段树
	tree[rt].l = l, tree[rt].r = r;				//初始化左右边界值
	if(l == r) {								//如果为叶节点，则更新值
		tree[rt].val = tree[rt].maxx = a[l];
		return;
	}
	int mid = (l+r)>>1;
	build(lson, l, mid);						//初始化左右子树
	build(rson, mid+1, r);
	push_up(rt);								//向上更新值
}
//rt为当前节点，pos为需要修改的位置，val为修改后的值
void update(int rt, int pos, ll val) {			//将pos位置的值修改为val
	int L = tree[rt].l, R = tree[rt].r;			//当前节点的左右边界
	if(L==R) {									//若为叶子节点，直接更新
		tree[rt].val = tree[rt].maxx = val;
		return;
	}
	int mid = (L+R)>>1;
	//更新pos对应的区间
	if(pos <= mid) update(lson, pos, val);
	else update(rson, pos, val);
	push_up(rt);								//向上更新值
}
//rt为当前节点，[l, r]为对应的查询区间
ll query(int rt, int l, int r) {				//计算区间[l, r]的和
	int L = tree[rt].l, R = tree[rt].r;			//当前节点的左右边界
	if(l <= L && R <= r) {						//如果包括当前区间，直接返回区间和
		return tree[rt].val;
	}
	int mid = (L+R)>>1;
	ll ans = 0;									//分别计算左右两个子树和
	if(l <= mid) ans += query(lson, l, r);
	if(r > mid) ans += query(rson, l, r);
	return ans;
}
//rt为当前节点，[l, r]为对应修改区间，x为模数
void modify(int rt, int l, int r, int x) {		//对区间[l, r]的所有值 %x
	int L = tree[rt].l, R = tree[rt].r;			//当前节点的左右边界
	if(tree[rt].maxx < x) return;				//如果当前区间最大值小于x，则无需操作，直接返回
	if(L==R) {									//否则需要单点修改
		tree[rt].val %= x;
		tree[rt].maxx %= x;
		return;
	}
	int mid = (L+R)>>1;							//分别判断左右子树是否需要修改
	if(l <= mid) modify(lson, l, r, x);
	if(r > mid) modify(rson, l, r, x);
	push_up(rt);								//向上更新值
}
int main() {
	fast;
	int n,m;
	cin>>n>>m;
	for(int i = 1;i <= n;i++) cin>>a[i];
	build(1, 1, n);//初始化建树
	while(m--) {
		int op, l, r, x;
		cin>>op>>l>>r;
		if(op==1) {
			cout<<query(1, l, r)<<"\n";
		}
		else if(op==2) {
			cin>>x;
			modify(1, l, r, x);
		}
		else {
			update(1, l, r);//pos为l，val为r
		}
	}
    return 0;
}
