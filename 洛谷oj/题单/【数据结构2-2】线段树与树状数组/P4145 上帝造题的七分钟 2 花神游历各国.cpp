// Problem: P4145 上帝造题的七分钟 2 / 花神游历各国
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P4145
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Author：Lese
// Time：2021-09-28 16:32:09

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

//题解：势能线段树
//对于每个位置的值a[i]，由于1开根号还是1
//所以其实每个位置的值大概只操作了 log_2 log_2 a 次
//那么对于区间[l, r]，可以直接暴力修改不为1的位置
//利用并查集来记录后一个 不为1 的位置

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
const double pi = acos(double(-1));
ll a[MAXN], tree[MAXN];//a记录原数据
int n,m, dis[MAXN];//dis记录后一个不为1的位置
int getf(int pos) {//路径压缩
	return pos==dis[pos]?pos:dis[pos]=getf(dis[pos]);
}
int lowbit(int x) { return x&(-x);}
void add(int pos, ll val) {//pos位置添加值val
	while(pos<=n) {
		tree[pos] += val;
		pos += lowbit(pos);
	}
}
ll ask(int pos) {//查询[1, pos]区间的值
	ll ans = 0;
	while(pos) {
		ans += tree[pos];
		pos -= lowbit(pos);
	}
	return ans;
}
int main() {
	cin>>n;
	for(int i = 1;i <= n;i++) {
		cin>>a[i];
		add(i, a[i]);
		//当前位置小于等于1，那么dis初始化为后一个位置，否则为当前位置
		if(a[i]<=1) dis[i] = i+1;
		else dis[i] = i;
	}
	cin>>m;
	for(int i = 1;i <= m;i++) {
		int op, l, r;
		cin>>op>>l>>r;
		if(l>r) swap(l, r);				//特判 l>r 的情况！！！
		if(op==1) {						//直接计算区间结果即可
			cout<<ask(r)-ask(l-1)<<"\n";
		}
		else {
			l = getf(l);//初始化l为 l开始的第一个不为1的位置
			while(l <= r) {
				//sqrt返回的是浮点数，注意强制类型转换！！！
				add(l, (ll) sqrt(a[l]) - a[l]);//原来为a[l], 现在为sqrt(a[l])
				a[l] = sqrt(a[l]);		//更新值
				if(a[l]<=1) {			//小于等于1，则向后转移
					dis[l] = getf(l+1);
				}
				int tmp = l;			//记录当前位置
				l = dis[l];				//寻找下一个不为1的位置
				if(tmp==l) l++;			//若为本身，则后移一位
			}
		}
	}
    return 0;
}
