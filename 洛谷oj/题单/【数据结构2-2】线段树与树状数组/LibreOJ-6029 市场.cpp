// Problem: 市场
// Contest: Virtual Judge - LibreOJ
// URL: https://vjudge.net/problem/LibreOJ-6029
// Memory Limit: 262 MB
// Time Limit: 2000 ms
// 
// Author：Lese
// Time：2021-10-08 10:22:53

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
#define LINF 0x7f7f7f7f7f7f7f7f
#define pii pair<int,int>
#define fi first
#define se second
#define eps 1e-6
#define lson rt<<1
#define rson rt<<1|1
#define L tree[rt].l
#define R tree[rt].r
using namespace std;

//题解：势能线段树
//对于一个区间来说，执行区间除操作时
//如果最小值的变化值 等于 最大值的变化值
//那么可以理解成一个区间减操作
//例如： 	3 3 3 4 4 ，其中区间除4
//那么结果为 0 0 0 1 1，对于每个位置其实都是-3，也就是说可以理解成区间-3的操作
//所以可以在原来的基础上，多维护一个区间最大值，来判断当前节点是否可以直接区间减操作
//注意：区间和操作和lazy操作的顺序！！！

const int MAXN = 1e5+5;
const int MOD = 1e9+7;
const double pi = acos(double(-1));
struct node {
	int l, r;//左右边界值
	ll val, maxx, minn, lazy;//区间和，区间最大值，区间最小值，区间标记
}tree[MAXN<<2];
int n, q;
ll a[MAXN];

inline char gch()
{
    static char buf[100010], *h = buf, *t = buf;
    return h == t && (t = (h = buf) + fread(buf, 1, 100000, stdin), h == t) ? EOF : *h ++;
}
template<class T>
inline void re(T &x) //快读
{
    x = 0;
    char a; bool b = 0;
    while(!isdigit(a = gch()))
        b = a == '-';
    while(isdigit(a))
        x = (x << 1) + (x << 3) + a - '0', a = gch();
    if(b == 1)
        x *= -1;
}
template <typename T>
void o(T p) {//快写（其实没快多少）
    static int stk[70], tp;
    if (p == 0) {
        putchar('0');
        return;
    }
    if (p < 0) {
        p = -p;
        putchar('-');
    }
    while (p) stk[++tp] = p % 10, p /= 10;
    while (tp) putchar(stk[tp--] + '0');
}

void push_up(int rt) {//向上更新值
	tree[rt].val = tree[lson].val + tree[rson].val;
	tree[rt].minn = min(tree[lson].minn, tree[rson].minn);
	tree[rt].maxx = max(tree[lson].maxx, tree[rson].maxx);
}
void push_down(int rt, int l, int mid, int r) {//向下传递标记
	if(tree[rt].lazy == 0) return;
	tree[lson].val += (mid-l+1) * tree[rt].lazy;
	tree[rson].val += (r-mid) * tree[rt].lazy;
	tree[lson].maxx += tree[rt].lazy;
	tree[rson].maxx += tree[rt].lazy;
	tree[lson].minn += tree[rt].lazy;
	tree[rson].minn += tree[rt].lazy;
	tree[lson].lazy += tree[rt].lazy;
	tree[rson].lazy += tree[rt].lazy;
	tree[rt].lazy = 0;
}
//rt为当前节点，[l, r]为初始化区间
void build(int rt, int l, int r) {//初始化建树
	tree[rt].l = l, tree[rt].r = r;
	tree[rt].maxx = -LINF, tree[rt].minn = LINF;
	tree[rt].lazy = 0;
	if(l==r) {
		tree[rt].val = tree[rt].maxx = tree[rt].minn = a[l];
		tree[rt].lazy = 0;
		return;
	}
	int mid = (l+r) >> 1;
	build(lson, l, mid);
	build(rson, mid+1, r);
	push_up(rt);
}
//rt为当前节点，[l, r]为修改区间，val为对应的值
void update(int rt, int l, int r, int val) {//区间[l, r]的值添加val
	// int L = tree[rt].l, R = tree[rt].r;//也可直接写，不用宏定义
	if(l <= L && R <= r) {
		tree[rt].val += (R-L+1) * val;
		tree[rt].maxx += val;
		tree[rt].minn += val;
		tree[rt].lazy += val;
		return;
	}
	int mid = (L+R) >> 1;
	push_down(rt, L, mid, R);
	if(l <= mid) update(lson, l, r, val);
	if(r > mid) update(rson, l, r, val);
	push_up(rt);
}
//rt为当前节点，[l, r]为修改区间，val为除数
void update_div(int rt, int l, int r, int val) {
	// int L = tree[rt].l, R = tree[rt].r;
	if(l <= L && R <= r) {
		ll tmp_min = tree[rt].minn - floor((double)tree[rt].minn/val);
		ll tmp_max = tree[rt].maxx - floor((double) tree[rt].maxx/val);
		if(tmp_min==tmp_max) {
			tree[rt].val -= tmp_min * (R-L+1);
			tree[rt].minn -= tmp_min;
			tree[rt].maxx -= tmp_min;
			tree[rt].lazy -= tmp_min;
			return;
		}
	}
	int mid = (L+R) >> 1;
	push_down(rt, L, mid, R);
	if(l <= mid) update_div(lson, l, r, val);
	if(r > mid) update_div(rson, l, r, val);
	push_up(rt);
}
//rt为当前节点，[l, r]为查询区间
ll query_min(int rt, int l, int r) {//查询区间[l, r]的最小值
	// int L = tree[rt].l, R = tree[rt].r;
	if(l <= L && R <= r) {
		return tree[rt].minn;
	}
	int mid = (L + R) >> 1;
	push_down(rt, L, mid, R);
	ll ans = LINF;
	if(l <= mid) ans = min(ans, query_min(lson, l, r));
	if(r > mid) ans = min(ans, query_min(rson,l, r));
	return ans;
}
//rt为当前节点，[l, r]为查询区间
ll query(int rt, int l, int r) {//查询区间[l, r]的总和
	// int L = tree[rt].l, R = tree[rt].r;
	if(l <= L && R <= r) {
		return tree[rt].val;
	}
	int mid = (L + R) >> 1;
	push_down(rt, L, mid, R);
	ll ans = 0;
	if(l <= mid) ans += query(lson, l, r);
	if(r > mid) ans += query(rson, l, r);
	return ans;
}
int main() {
	re(n), re(q);
	for(int i = 1;i <= n;i++) re(a[i]);
	build(1, 1, n);//初始化建树
	while(q--) {
		int op, l, r;
		ll v;
		re(op), re(l), re(r);
		++l, ++r;
		if(op==1) {
			re(v);
			update(1, l, r, v);
		}
		else if(op==2) {
			re(v);
			update_div(1, l, r, v);
		}
		else if(op==3) {
			o(query_min(1, l, r));//输出的差别不大！！！
			puts("");
		}
		else {
			o(query(1, l, r));
			puts("");
		}
	}
    return 0;
}
