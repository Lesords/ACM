// Problem: A - Find Multiple
// Contest: AtCoder - AtCoder Beginner Contest 220
// URL: https://atcoder.jp/contests/abc220/tasks/abc220_a
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Author：Lese
// Time：2021-09-26 20:00:10

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
const int MAXN = 2e5+5;
const int MOD = 1e9+7;
const double pi = acos(double(-1));
int main() {
	int a,b,c;
	cin>>a>>b>>c;
	for(int i = a;i <= b;i++) {
		if(i%c==0) {
			cout<<i<<"\n";
			return 0;
		}
	}
	cout<<"-1\n";
    return 0;
}
