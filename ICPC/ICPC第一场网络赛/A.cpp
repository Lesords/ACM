#include<iostream>//ac
#include<cstring>
#include<cstdio>
#include<cmath>
#include<string>
#include<sstream>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<utility>
#include<bitset>
#include<algorithm>
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
using namespace std;

//题解：线段树 + 二分区间
//利用线段树来记录对应节点的结束时间，然后区间维护结束时间的最小值
//由于会出现环的情况（也就是后部分会连接到开头），所以可以开两倍空间的线段树
//然后每次查询的时候，先判断是否存在节点为空闲的情况，若都为忙碌直接跳过
//否则以当前位置为起点，二分长度为k的区间
//每次判断前一半区间是否满足条件，满足则缩小右区间，否则缩小左区间
//注意：二分对应的是区间，而不是一个点！！！

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
struct dot{
	int l, r;
	ll val;
}tree[MAXN<<2];

ll num[MAXN];//记录对应节点的执行次数

void build(int rt,int l, int r) {
	tree[rt].l = l, tree[rt].r = r;
	if(l==r) {
		return ;
	}
	int mid = (l+r)>>1;
	build(rt<<1, l, mid);
	build(rt<<1|1, mid+1, r);
}
ll query(int rt,int l, int r) {//查询[l, r]区间范围的最小值
	int L = tree[rt].l;
	int R = tree[rt].r;
	if(l <= L && R <= r) {
		return tree[rt].val;
	}
	int mid = (L+R)>>1;
	ll ans = INF;
	if(l<=mid) ans = min(ans, query(rt<<1, l, r));
	if(r> mid) ans = min(ans, query(rt<<1|1, l, r));
	return ans;
}
void update(int rt, int val, ll kk) {//将点val的值修改为kk
	int L = tree[rt].l;
	int R = tree[rt].r;
	if(L==R) {
		tree[rt].val = kk;
		return ;
	}
	int mid = (L+R)>>1;
	if(val <= mid) update(rt<<1, val, kk);
	else update(rt<<1|1, val, kk);
	tree[rt].val = min(tree[rt<<1].val, tree[rt<<1|1].val);
}
int main() {
	fast;
	int k,n;
	cin>>k>>n;
	build(1, 1, k*2);//线段树计算的节点编号为 1-2*k
	for(int i = 0;i < n;i++) {
		ll a, b;
		cin>>a>>b;
		if(query(1, 1, 2*k) >= a) continue;//全部节点都在忙碌，则跳过
		ll ed = a + b - 1;//当前的结束时间
		int l = i%k+1, r = i%k + k;//注意左右区间的值（长度只需要为k，避免重复）
		while(l <= r) {
			int mid = (l+r)>>1;
			if(query(1, l, mid) < a) {
				r = mid-1;//此时r+1可能满足条件，所有当l = r时，l = mid+1即为结果
			}
			else l = mid+1;
		}
		update(1, l, ed);//修改l位置的值
		//由于为两倍空间，所以还需要修改另外一个位置的值
		if(l > k) {
			num[l-k]++;//记录对应数量的执行次数
			update(1, l-k, ed);
		}
		else {
			num[l]++;//记录对应数量的执行次数
			update(1, l+k, ed);
		}
	}
	
	//记录结果
	int ans = 0,index = 0;
	for(int i = 1;i <= k;i++) {
		if(num[i]>=ans) {
			ans = num[i];
			index = i;
		}
	}
	vector<int> res;
	for(int i = 1;i <= k;i++) {//按照数字大小顺序来记录
		if(num[i]==ans) {
			res.push_back(i);
		}
	}
	for(int i = 0;i < res.size();i++) {
		if(i) cout<<" ";
		cout<<res[i]-1;//计算的节点编号从1开始，所以需-1
	}
	return 0;
}