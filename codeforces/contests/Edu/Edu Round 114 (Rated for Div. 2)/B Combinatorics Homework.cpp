// Problem: B. Combinatorics Homework
// Contest: Codeforces - Educational Codeforces Round 114 (Rated for Div. 2)
// URL: https://codeforces.ml/contest/1574/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Author：Lese
// Time：2021-09-20 22:45:02

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

//题解：组合+构造
//首先需要计算最大值，然后计算最小值
//如果题目要求的数量k在范围内，则满足；否则不满足

//1. 对于相邻数量最大的情况即为所有的字符分类排列，例如 AAABBBCCC
//2. 对于相邻数量最小的情况即先将字符混合排列，然后剩余两个字符继续混合排列
//然后剩余一个字符可以插在前面三个字符混合排列的缝隙中
//例如： ABC ABC ABC ABC ABABABAB   B B B
//观察可得对应的缝隙数量为 三个混合排列的数量+1（两个混合排列可以理解为一个独立块）

//对于在范围内的相邻数肯定会有一种情况满足条件的！！！
//例：AAABBBCCC	=>	CAAABBBCC	=>	CACAABBBC => CACACABBB => CBACACABB
// => CBABCACAB

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
const double pi = acos(double(-1));
int main() {
    int t;
    cin>>t;
    while(t--) {
    	ll a[4], m, sum = 0;
    	for(int i = 1;i <= 3;i++) cin>>a[i],sum += a[i];
    	sort(a+1, a+4);
    	cin>>m;
    	ll maxx = sum-3;//总和-3 即为最大的相邻数
    	if(m>maxx) {
    		cout<<"NO\n";
    		continue;
    	}
    	for(int i = 2;i <= 3;i++) a[i] -= a[1];//扣除三个混合排列的数量a[1]
    	//a[3]-a[2]扣除了两个混合排列的数量
    	ll minn = a[3]-a[2] -a[1]-1;// -a[1]-1 扣除了三个混合排列中的缝隙数量
    	if(m<minn) {//小于最小值，也无解
    		cout<<"NO\n";
    		continue;
    	}
    	cout<<"YES\n";
    }
    return 0;
}
