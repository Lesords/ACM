// Problem: C. Save More Mice
// Contest: Codeforces - Codeforces Round #748 (Div. 3)
// URL: https://codeforces.ml/contest/1593/problem/C
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// Author：Lese
// Time：2021-10-13 22:58:17

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
const int MAXN = 4e5+5;
const int MOD = 1e9+7;
const double pi = acos(double(-1));
ll a[MAXN];
int main() {
    int t;
    cin>>t;
    while(t--) {
    	int n, k;
    	cin >> n >> k;
    	for(int i = 1;i <= k;i++) {
    		cin >> a[i];
    	}
    	sort(a+1, a+k+1);
    	ll sum = 0, ans = 0;
    	for(int i = k;i >= 1;i--) {
    		if(sum < a[i]) ans++;//只剩余一个时，可以保持距离一起前走
    		sum += n-a[i];
    	}
    	cout << ans << "\n";
    }
    return 0;
}
