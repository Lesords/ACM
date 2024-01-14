// Problem: F - Parenthesis Checking
// Contest: AtCoder - AtCoder Beginner Contest 223
// URL: https://atcoder.jp/contests/abc223/tasks/abc223_f
// Memory Limit: 1024 MB
// Time Limit: 3000 ms
// 
// Author：Lese
// Time：2021-11-10 15:39:53

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

//题意：给定一个包含左括号和右括号的字符串，在其进行两个操作
//1 l r :交换位置l和位置r的字符
//2 l r :查询区间[l, r]内的括号是否满足条件

//题解；如果将 ( 记为1，将 ) 记为-1
//那么对于满足条件的区间和结果为0
//例如 ()(())	1 + (-1) + 1 + 1 + (-1) + (-1) = 0
//并且前缀和的最小值不能为负数
//例如 ))((		-1 + (-1) + 1 + 1
//虽然区间和为0，但是前缀和出现-1和-2的情况，所以不满足条件
//那么可以将本题转换为维护 区间和 和 前缀和最小值的情况
//区间和直接维护即可，需要注意的是维护 前缀和最小值的情况
//左区间的前缀和最小值直接维护即可，但是右区间的前缀和最小值需要累加上左区间和才可！！！
//即为 tree[rt].minn = min(tree[lson].minn, tree[lson].sum + tree[rson].minn)

//1. 对于交换操作，直接将对应位置的两个值交换，然后进行两次单点修改即可
//2. 对于查询操作，需要判断区间和是否为0，并且区间前缀和的最小值是否也为0

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
const double pi = acos(double(-1));
struct node{
	int l, r;				//当前点的左右区间
	int sum, minn;			//区间和，前缀和最小值
}tree[MAXN<<2];
char s[MAXN];				//原字符串
int a[MAXN];				//字符对应的数值
void push_up(int rt) {		//向上传递
	tree[rt].sum = tree[lson].sum + tree[rson].sum;
	//右区间前缀和最小值 需要加上 左区间和！！！
	tree[rt].minn = min(tree[lson].minn, tree[lson].sum+tree[rson].minn);
}
//rt为当前节点，[l, r]为当前区间
void build(int rt, int l, int r) {//初始化建树
	tree[rt].l = l, tree[rt].r = r;
	if(l==r) {				//若为叶子节点，更新对应值
		tree[rt].sum = tree[rt].minn = a[l];
		return;
	}
	int mid = (l+r)>>1;
	build(lson, l, mid);	//分别初始化左右子树
	build(rson, mid+1, r);
	push_up(rt);
}
//rt为当前节点，pos为需要更新的位置
void update(int rt, int pos) {			//更新pos位置的值
	int L = tree[rt].l, R = tree[rt].r;	//当前节点左右边界
	if(L==R) {//如果叶子节点（即为需要更新的位置），更新对应值
		tree[rt].sum = tree[rt].minn = a[pos];
		return;
	}
	int mid = (L+R)>>1;
	//判断需要修改的位置在左子树还是右子树，更新对应的子树
	if(pos <= mid) update(lson, pos);
	else update(rson, pos);
	push_up(rt);
}
//rt为当前节点，[l, r]为查询区间
int query_sum(int rt, int l, int r) {	//查询区间[l, r]的和
	int L = tree[rt].l, R = tree[rt].r;	//当前节点对应的左右区间
	if(l <= L && R <= r) {				//若查询区间包括当前节点区间，直接返回结果
		return tree[rt].sum;
	}
	int mid = (L+R) >> 1;
	int ans = 0;
	//判断左右子树是否有交集，若有，累加
	if(l <= mid) ans += query_sum(lson, l, r);
	if(r > mid) ans += query_sum(rson, l, r);
	return ans;
}
//rt为当前节点，[l, r]为查询区间
int query_min(int rt, int l, int r) {	//查询区间[l, r]的前缀和最小值
	int L = tree[rt].l, R = tree[rt].r;	//当前节点的左右区间
	if(l <= L && R <= r) {				//若查询区间包括当前节点，直接返回结果
		return tree[rt].minn;
	}
	int mid = (L+R) >> 1;
	int minn = INF;
	//左子树，直接取最小值即可
	if(l <= mid) minn = min(minn, query_min(lson, l, r));
	//右子树需要累计对应左子树的区间和（注意，左子树区间为[l, mid]）
	if(r > mid) minn = min(minn, query_sum(lson, l, mid)+ query_min(rson, l, r));
	return minn;
}
int main() {
	int n, m;
	cin >> n >> m >> (s+1);
	for(int i = 1;i <= n;i++) {
		a[i] = s[i]=='('?1:-1;		//计算对应字符的值
	}
	build(1, 1, n);					//初始化线段树
	while(m--) {
		int op, l, r;
		cin >> op >> l >> r;
		if(op==1) {
			//判断条件直接为数值，无需为原字符，即无需对原字符进行操作
			if(a[l]==a[r]) continue;//如果两个位置的值相等，跳过（交换后值也一样）
			swap(a[l], a[r]);		//交换对应位置的值
			update(1, l), update(1, r);//更新两个位置的对应值
		}
		else {
			//区间和为0 并且 前缀和最小值也为0 才满足条件
			if(query_sum(1, l, r) == 0 && query_min(1, l, r) == 0) {
				cout << "Yes\n";
			}
			else cout << "No\n";
		}
	}
    return 0;
}
