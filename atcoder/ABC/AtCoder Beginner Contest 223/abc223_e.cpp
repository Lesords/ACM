// Problem: E - Placing Rectangles
// Contest: AtCoder - AtCoder Beginner Contest 223
// URL: https://atcoder.jp/contests/abc223/tasks/abc223_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Author：Lese
// Time：2021-10-17 20:44:11

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

//题意：在一个长x宽y的矩形范围内，放置三个面积为a, b, c的矩形，判断是否可行
//题解：首先考虑只需要放置两个矩形的情况
//很显然，只有两个情况，垂直摆放和水平摆放（技巧：直接交换x和y大小）
//那么对于放置三个矩形的情况来说
//可以分解为一个矩形+两个矩形，也就是说先确定一个矩形，然后再判断剩余的矩形
//很显然，这个也有垂直摆放和水平摆放的区别
//并且对于 一个矩形+两个矩形 的选择共有三种
// 1: (a,b) c
// 2: (b,c) a （将后两个提前）
// 3: (c,a) b （将后两个提前）
//对应操作技巧为：swap(a, b), swap(b, c) （分别将b和c提前）
//注意：记得向上取整，以及判断第一个矩形是否满足条件


const int MAXN = 2e5+5;
const int MOD = 1e9+7;
const double pi = acos(double(-1));
ll x, y, a, b, c;
//长x宽y的矩形范围内 放置 面积为a,b的两个矩形
bool solve2(ll x, ll y, ll a, ll b) {
	for(int i = 1;i <= 2;i++) {//两个摆放方式
		ll len1 = (a+x-1)/x;//对应占有的高度
		ll len2 = (b+x-1)/x;
		if(len1+len2 <= y) return true;
		swap(x, y);//交换x，y值，相当于将摆放方式旋转90度（垂直->水平）
	}
	return false;
}
//长x宽y的矩形范围内 放置 面积为a, b, c的三个矩形
bool solve(ll x, ll y, ll a, ll b, ll c) {
	for(int i = 1;i <= 2;i++) {//两个摆放方式
		for(int j = 1;j <= 3;j++) {//三种组合
			ll len = (c+x-1)/x;//第一个矩形占据的高度
			//注意：高度不能超过y！！！
			//扣除高度len，继续判断剩余矩形a和b的是否可以放置
			if(len < y && solve2(x, y-len, a, b)) {
				return true;
			}
			swap(a, b);
			swap(b, c);
		}
		swap(x, y);
	}
	return false;
}
int main() {
	cin >> x >> y >> a >> b >> c;
	cout << (solve(x, y, a, b, c)?"Yes\n":"No\n");
    return 0;
}