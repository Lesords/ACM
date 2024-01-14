// Problem: D - Online games
// Contest: AtCoder - AtCoder Beginner Contest 221
// URL: https://atcoder.jp/contests/abc221/tasks/abc221_d
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Author：Lese
// Time：2021-10-02 20:00:58

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

//题意：每个人都有对应的在线时间段，给出n个人的在线时间段
//求同时有k个人在线的时间长度 (1 <= k <= n)

//题解：离散化后差分前缀和
//由于差分是对结束的后一点进行操作，所以离散化时记录的数据为 结束的后一点 和 起点
//最后前缀和的时候累加答案
//先初始化起点的在线人数，然后每遍历到一个位置，那么 [上一个位置, 当前位置) 即为当前在线人数的区间
//所以需要先更新答案，然后再更新在线人数

const int MAXN = 5e5+5;
const int MOD = 1e9+7;
const double pi = acos(double(-1));
vector<ll> all;//记录所有需要操作的数据（起点和终点后一位）
ll a[MAXN], b[MAXN], num[MAXN], dif[MAXN];//a为起点，b为结束后一点
//num为在线人数i的时长，dif记录差分（区间人数）
int getp(ll val) {//获取val离散后的值
	return lower_bound(all.begin(), all.end(), val) - all.begin();
}
int main() {
	int n;
	cin>>n;
	for(int i = 1;i <= n;i++) {
		cin>>a[i]>>b[i];
		b[i] = a[i] + b[i];//结束后一个时间点
		all.push_back(a[i]);
		all.push_back(b[i]);
	}
	sort(all.begin(), all.end());//排序
	all.erase(unique(all.begin(), all.end()), all.end());//去重并删除重复值
	int siz = all.size();//siz为差分数组的大小
	for(int i = 1;i <= n;i++) {
		int one = getp(a[i]), two = getp(b[i]);//获取离散后的值
		dif[one]++, dif[two]--;//差分操作
	}
	//记录起点（差分数组从0开始）
	int sum = dif[0];//对差分取前缀和，表示当前区间在线的人数
	int last = 1;//时间从1开始（last为上一个位置的时间）
	for(int i = 1;i < siz;i++) {//从1开始计算（0是起点，后面的才有终点）
		//先计算结果后更新
		num[sum] += all[i]-all[i-1];//[上一个位置, 当前位置)即为当前区间的人数
		sum += dif[i];
	}
	for(int i = 1;i <= n;i++) cout<<num[i]<<" ";
    return 0;
}
