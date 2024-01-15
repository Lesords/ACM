// Problem: B. Vlad and Candies
// Contest: Codeforces - Codeforces Round #780 (Div. 3)
// URL: https://codeforces.ml/contest/1660/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Author：Lese
// Time：2022-03-31 22:39:42

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
int a[MAXN];
int main() {
    int t;
    cin>>t;
    while(t--) {
    	int n;
    	cin >> n;
    	for(int i = 1;i <= n;i++) {
    		cin >> a[i];
    	}
    	sort(a+1, a+1+n);
    	if(n == 1) {
    		if(a[1] == 1) cout << "YES\n";
    		else cout << "NO\n";
    	}
    	else {
    		if(a[n] > a[n-1]+1) cout << "NO\n";
    		else cout << "YES\n";
    	}
    }
    return 0;
}
