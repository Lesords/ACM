// Problem: F. SUM and REPLACE
// Contest: Codeforces - Educational Codeforces Round 37 (Rated for Div. 2)
// URL: https://codeforces.ml/problemset/problem/920/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Author：Lese
// Time：2021-10-07 19:47:20

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

//题解：势能线段树
//先线性筛预处理每个数的因子个数
//由于对于小于3的数（不包括3），对应因子数为本身（1和2）
//也就是说小于3的数，可以无需操作
//那么可以在线段树中，维护区间最大值，如果区间最大值小于3，则跳过
//否则逐个修改

const int MOD = 1e9+7;
const double pi = acos(double(-1));

const int MAXM = 3e5+5;
const int MAXV = 1e6;//数组长度！！！
const int MAXN = 8e4;//共78498个质数
//注意数组大小，取MAXV！！！
int prim[MAXN], v[MAXV+10], cnt, num[MAXV+10], d[MAXV+10];//v记录最小质因子
//num为对应数字的最小质因子出现次数，d为对应数字的因子个数

struct node{
	int l, r;
	ll val, maxx;
}tree[MAXM<<2];
int n, m, a[MAXM];
void get_prim() {//线性筛求因数个数
	d[1] = 1;
    for(int i = 2;i <= MAXV;i++) {
        if(v[i]==0) {
            prim[++cnt] = i;
            v[i] = i;
            d[i] = 2;//质数的因子有两个
            num[i] = 1;//最小质因子数量只有一个
        }
        for(int j = 1;j <= cnt;j++) {
            if(i*1ll*prim[j]>MAXV) break;
            v[i*prim[j]] = prim[j];
            //1. 如果i中没有 prim[j] 因子，说明 i*prim[j] 中相对于 i 中多了个prim[j]
            //所以 因子个数的结果需要 乘以 2（d[prim]）
            //又由于遍历的质因子是从小到大的，所以当前的质因子即为最小的因子，则为1
            //2. 如果i中有 prim[j] 因子，那么需要扣除原来的值，再乘以新的值
            //原来的值为 num[i]+1，新的值为 num[i]+2（多了一个因子）
            //对应的最小质因子数量为 num[i]+1（多了当前的一个prim[j]）
            if(i%prim[j]) {
            	d[i*prim[j]] = d[i] * d[prim[j]];
            	num[i*prim[j]] = 1;
            }
            else {
            	d[i*prim[j]] = d[i] / (num[i]+1) * (num[i]+2);
            	num[i*prim[j]] = num[i]+1;
            	break;//线性筛重点！！！
            }
        }
    }
}


void push_up(int rt) {								//向上更新
	tree[rt].val = tree[lson].val + tree[rson].val;
	tree[rt].maxx = max(tree[lson].maxx, tree[rson].maxx);
}
//rt为当前节点，[l, r]为当前初始化区间
void build(int rt, int l, int r) {					//初始化建树
	tree[rt].l = l, tree[rt].r = r;					//当前节点的左右边界值
	if(l==r) {										//到达叶子节点，则更新对应值
		tree[rt].maxx = tree[rt].val = a[l];
		return;
	}
	int mid = (l+r)>>1;
	build(lson, l, mid);							//分别初始化左右子树
	build(rson, mid+1, r);
	push_up(rt);									//向上更新值
}
//rt为当前节点，[l, r]为查询区间
ll query(int rt, int l, int r) {					//查询区间[l, r]的总和
	int L = tree[rt].l, R = tree[rt].r;				//当前节点的左右边界值
	if(l <= L && R <= r) {							//如果包括当前节点的区间，直接返回区间和
		return tree[rt].val;
	}
	int mid = (L + R)>>1;
	ll ans = 0;
	//判断左右子树是否有涉及查询区间，若有则累加
	if(l <= mid) ans += query(lson, l, r);
	if(r > mid) ans += query(rson, l, r);
	return ans;
}
//rt为当前节点，[l, r]为修改区间
void update(int rt, int l, int r) {					//修改[l, r]区间内的值为其因子个数
	int L = tree[rt].l, R = tree[rt].r;				//当前节点的左右边界值
	if(tree[rt].maxx < 3) {							//如果当前节点的区间最大值小于3，则无需操作，直接返回
		return;
	}
	if(L==R) {										//否则逐个修改
		tree[rt].maxx = tree[rt].val = d[tree[rt].val];
		return;
	}
	int mid = (L+R) >> 1;
	//分别判断左右子树是否有涉及修改区间，如有则更新
	if(l <= mid) update(lson, l, r);
	if(r > mid) update(rson, l, r);
	push_up(rt);									//向上更新值
}
int main() {
	fast;											//关同步防止TLE
	get_prim();
	cin>>n>>m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	build(1, 1, n);									//初始化建树
	while(m--) {
		int op, l, r;
		cin >> op >> l >> r;
		if(op==1) {									//1为更新，2位查询
			update(1, l, r);
		}
		else {
			cout << query(1, l, r) << "\n";
		}
	}
    return 0;
}