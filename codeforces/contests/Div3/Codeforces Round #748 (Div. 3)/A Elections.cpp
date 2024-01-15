// Problem: A. Elections
// Contest: Codeforces - Codeforces Round #748 (Div. 3)
// URL: https://codeforces.ml/contest/1593/problem/0
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Author：Lese
// Time：2021-10-13 22:35:19

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
    int t;
    cin>>t;
    while(t--) {
    	int a, b, c;
    	cin >> a >> b >> c;
    	cout << max(max(b, c)-a+1, 0);
    	cout << " " << max(max(a, c) - b+1, 0);
    	cout << " " << max(max(a, b) - c+1, 0);
    	cout <<"\n";
    }
    return 0;
}
