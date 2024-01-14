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
//首先需要知道，欧拉函数的值 和一个数的质因子分解有关
//1. 设 p 为质数，若p|n 且 p^2|n，则phi[i] = phi[i/p] * p
//2. 设 p 为质数，若p|n 且 p^2不整除n，则phi[i] = phi[i/p] * (p-1)
//由于一个数可以分解成多个质因子相乘，那么对于区间操作 *w，可以理解成 乘 多个质因子
//则有：如果原来的数包含当前的质因子p，那么结果 * p;
//如果原来的数不包含当前的质因子p，那么结果 * (p-1)。

//由于数据范围只有100，所以可以先处理所有数的质因子出现次数（线段树中用bitset优化）
//预处理次数是为了区间操作的次数（多次乘同一个质因子）
//线段树中的bitset是为了方便记录当前区间的所有值是否包含该因子，如果都包含，直接区间 * 质因子
//那么对于区间乘 w，可以遍历所有质因子（只有25个），如果w包含该质因子
//那么对于该区间进行 * 该质因子
//查询操作时，注意不要修改区间边界值！！！

const int MAXN = 1e5+5;
const int MOD = 998244353;
const double pi = acos(double(-1));
struct node {
	int l, r;
	ll val, lazy;		//val为当前节点值（区间和）
	bitset<30> mark;	//记录是否包含对应位置的质因子（如果为1表示包含）
}tree[MAXN<<2];
bitset<30> all[101];	//记录所有数字的质因子包含情况（方便线段树初始化）
int a[MAXN];			//原数据
int prim[30], vis[101], num[101][30], phi[101];//prim记录质数，vis表示当前数是否为质数
//num记录每个值对应位置质数的出现次数，phi记录对应欧拉函数值（方便线段树初始化）
int cnt;				//记录质数数量

int cal_phi(int n) {	//计算n的欧拉函数值
	int m = int(sqrt(n + 0.5));
	int ans = n;
	for (int i = 2; i <= m; i++)
		if (n % i == 0) {
			ans = ans / i * (i - 1);
			while (n % i == 0) n /= i;
		}
	if (n > 1) ans = ans / n * (n - 1);
	return ans;
}
void init() {								//初始化对应信息
	for(int i = 2;i <= 100;i++) {			//计算100范围内的质数
		if(vis[i]==0) {
			prim[++cnt] = i;
		} 
		for(int j = i + i;j <= 100;j += i) vis[j] = 1;
	}//cnt为25
	for(int i = 2;i <= 100;i++) {			//遍历所有值
		for(int j = 1;j <= cnt;j++) {		//遍历所有的质数
			int tmp = i;
			while(tmp%prim[j]==0) num[i][j]++, tmp /= prim[j];
			all[i][j] = num[i][j];			//记录i值中j质数出现的次数
		}
	}
	for(int i = 1;i <= 100;i++) phi[i] = cal_phi(i);//计算所有欧拉函数
}

void push_up(int rt) {						//更新值
	tree[rt].val = (tree[lson].val + tree[rson].val)%MOD;
	//左右子区间都需要包含对应质数，所以取 &
	tree[rt].mark = tree[lson].mark & tree[rson].mark;
}
//rt为当前节点编号，l为左区间，mid中间值，r为右区间
void push_down(int rt, int l, int mid, int r) {//传递标记
	if(tree[rt].lazy!=1) {
		//标记下传
		tree[lson].lazy = (tree[lson].lazy * tree[rt].lazy)%MOD;
		tree[rson].lazy = (tree[rson].lazy * tree[rt].lazy)%MOD;
		//计算标记对子区间的贡献
		tree[lson].val = (tree[lson].val * tree[rt].lazy)%MOD;
		tree[rson].val = (tree[rson].val * tree[rt].lazy)%MOD;
		tree[rt].lazy = 1;//标记还原为1
	}	
}
//rt为当前节点，[l, r]为初始化区间范围
void build(int rt, int l, int r) {			//初始化线段树
	tree[rt].l = l, tree[rt].r = r;			//当前节点信息
	tree[rt].lazy = 1;
	if(l==r) {								//叶子节点
		tree[rt].val = phi[a[l]];
		tree[rt].mark = all[a[l]];
		return;
	}
	int mid = (l+r)>>1;
	build(lson, l, mid);					//分别建立左右子树
	build(rson, mid+1, r);
	push_up(rt);
}
//rt为当前节点，[l, r]为查询区间
ll query(int rt, int l, int r) {			//查询区间[l, r]的值
	int L = tree[rt].l, R = tree[rt].r;
	if(l <= L && R <= r) {//包含当前节点，直接返回节点值
		return tree[rt].val%MOD;
	}
	ll ans = 0;
	int mid = (L+R)>>1;
	push_down(rt, L, mid, R);				//下传标记
	//查询时, [l, r]区间大小不要变化
	if(l <= mid) ans = (ans + query(lson, l, r))%MOD;
	if(r > mid) ans = (ans + query(rson, l, r))%MOD;
	return ans;
} 
//rt为当前节点，[l, r]为操作区间，pos为对应的质数位置，num为该质数需要操作的次数
void update(int rt, int l, int r, int pos, int num) {//修改区间[l, r]
	int L = tree[rt].l, R = tree[rt].r;
	//如果包含该节点区间，并且该区间所有位置包含了当前质数，区间更新
	if(l <= L && R <= r && tree[rt].mark[pos]) {
		for(int i = 1;i <= num;i++) {		//操作num次
			tree[rt].val = (tree[rt].val * prim[pos]) % MOD;
			tree[rt].lazy = (tree[rt].lazy * prim[pos]) % MOD;
		}
		return;
	}
	//否则需要逐个修改（遍历到叶节点位置）
	if(L==R) {
		//第一次不包括当前质数
		tree[rt].val = (tree[rt].val * (prim[pos]-1))%MOD;
		tree[rt].mark[pos] = 1;				//记得标记！！！
		//num-1次操作时，包含了当前质数
		for(int i = 1;i < num;i++) {
			tree[rt].val = (tree[rt].val * prim[pos])%MOD;
		}
		return;
	}
	int mid = (L+R)>>1;
	push_down(rt, L, mid, R);				//下传标记
	//分别判断左右区间，若包括则继续更新
	if(l <= mid) update(lson, l, r, pos, num);
	if(r > mid) update(rson, l, r, pos, num);
	push_up(rt);							//更新值
}
int main() {
	fast;
	init();//初始化对应信息（质数，欧拉函数等）
	int n, m;
	cin>>n>>m;
	for(int i = 1;i <= n;i++) {
		cin>>a[i];
	}
	build(1, 1, n);//初始化建树
	while(m--) {
		int op, l, r, w;
		cin>>op>>l>>r;
		if(op==0) {
			cin>>w;
			for(int i = 1;i <= cnt;i++) {	//遍历所有的质数（共cnt个）
				if(num[w][i]) {//若当前w包含了i位置的质数，则需要操作
					update(1, l, r, i, num[w][i]);
				}
			}
		}
		else {
			cout<<query(1, l, r)<<"\n";
		}
	}
    return 0;
}
