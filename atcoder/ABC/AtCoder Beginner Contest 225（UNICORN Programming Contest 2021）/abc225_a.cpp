// Problem: A - Distinct Strings
// Contest: AtCoder - UNICORN Programming Contest 2021(AtCoder Beginner Contest 225)
// URL: https://atcoder.jp/contests/abc225/tasks/abc225_a
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Author：Lese
// Time：2021-11-09 20:35:41

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
const int MAXN = 2e5+5;
const int MOD = 1e9+7;
const double pi = acos(double(-1));
int main() {
	string s;
	cin >> s;
	set<char> st;
	for(int i = 0;i < s.size();i++) {
		st.insert(s[i]);
	}
	if(st.size()==1) cout << "1";
	else if(st.size()==2) cout << "3";
	else cout << "6";
    return 0;
}
