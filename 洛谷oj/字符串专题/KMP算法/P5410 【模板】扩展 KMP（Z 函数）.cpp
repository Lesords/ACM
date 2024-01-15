// Problem: P5410 【模板】扩展 KMP（Z 函数）
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P5410
// Memory Limit: 500 MB
// Time Limit: 1000 ms
// 
// Author：Lese
// Time：2021-09-16 11:17:58

#include<iostream>
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
const int MOD = 1e9+7;
const double pi = acos(double(-1));

//nxt[i]: b[i···n-1]与b的LCP值
//extend[i]: a[i···n-1]与b的LCP值
const int MAXN = 2e7+5;
int nxt[MAXN], extend[MAXN];
void pre_exkmp(string s) {
	int n = (int)s.length();
	nxt[0] = n;
	//[l, r]为z-box区间
	for(int i = 1, l = 0, r = 0;i < n;++i) {
		//满足z-box区间内，那么可以直接更新
		if(i <= r && nxt[i - l] < r - i + 1) {//r-i+1为剩余区间大小
			nxt[i] = nxt[i - l];
		}
		else {
			nxt[i] = max(0, r - i + 1);
			//否则需要继续逐个匹配（z-box区间对应开头区间的位置）
			while(i + nxt[i] < n && s[nxt[i]] == s[i + nxt[i]]) ++nxt[i];
		}
		//更新z-box区间
		if(i + nxt[i] - 1 > r) l = i, r = i + nxt[i] - 1;
	}
}
void exkmp(string a, string b) {//a为长串，b为短串
	pre_exkmp(b);
	int n = a.size();
	while(a[extend[0]] == b[extend[0]]) extend[0]++;//特判第一位置的值
	for(int i = 1,l = 0, r = 0;i < n; ++i) {
		//满足z-box区间内，那么可以直接更新
		if(i <= r && nxt[i-l] < r - i + 1) {
			extend[i] = nxt[i - l];
		}
		else {
			extend[i] = max(0, r - i + 1);
			//否则需要继续逐个匹配（z-box区间对应开头区间的位置）
			while(i + extend[i] < n && b[extend[i]] == a[i + extend[i]]) 
				++extend[i];
		}
		//更新z-box区间
		if(i + extend[i] - 1 > r) l = i, r = i + extend[i] - 1;
	}
}

int main() {
	fast;
	string n,m;
	cin>>n>>m;
	exkmp(n, m);
	ll ans = 0;
	//计算完LCP，直接异或求解即可
	for(int i = 0;i < m.size();i++) {
		ans ^= (i+1)*1ll*(nxt[i]+1);
	}
	cout<<ans<<"\n";
	ans = 0;
	for(int i = 0;i < n.size();i++) {
		ans ^= (i+1)*1ll*(extend[i]+1);
	}
	cout<<ans;
    return 0;
}
