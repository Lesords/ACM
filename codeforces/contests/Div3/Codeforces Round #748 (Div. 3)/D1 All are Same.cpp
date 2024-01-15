// Problem: D1. All are Same
// Contest: Codeforces - Codeforces Round #748 (Div. 3)
// URL: https://codeforces.ml/contest/1593/problem/D1
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Author：Lese
// Time：2021-10-13 23:15:06

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

//题解：将所有数值从小到大排序
//然后计算所有差值的最大公因数

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
const double pi = acos(double(-1));
int a[50];
int gcd(int a, int b) {
	return a%b==0?b:gcd(b, a%b);
}
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
    	int pos = unique(a+1, a+1+n) - a-1;
    	if(pos==1) {//所有值都相等，则为-1
    		cout << "-1\n";
    		continue;
    	}
    	int dif = 0, ans = 0;
    	ans = a[2] - a[1];
    	for(int i = 3;i <= pos;i++) {
    		dif = a[i] - a[i-1];
    		ans = gcd(ans, dif);
    	}
    	cout << ans << "\n";
    }
    return 0;
}
