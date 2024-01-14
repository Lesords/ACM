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
const int MAXN = 1e6+5;
const int MOD = 1e9+7;
const double pi = acos(double(-1));
int dp[MAXN], ans[MAXN], a[MAXN];
int get_pos(int l, int r, int val) {
	int ans = 0;
	while(l <= r) {
		int mid = (l+r) >> 1;
		if(dp[mid] <= val) r = mid-1, ans = mid;
		else l = mid+1;
	}
	return ans;
}
int main() {
	fast;
    int t;
    cin>>t;
    while(t--) {
    	int n;
    	cin >> n;
    	for(int i = 1;i <= n;i++) cin >> a[i];
    	int top = 1;
    	ans[1] = 1;
    	dp[1] = a[1];
    	for(int i = 2;i <= n;i++) {
    		if(a[i] < dp[top]) {
    			dp[++top] = a[i];
    			ans[i] = top;
    			continue;
    		}
    		int pos = get_pos(1, top, a[i]);
    		ans[i] = pos;
    		dp[pos] = a[i];
    	}
    	cout << top << "\n";
    	for(int i = 1;i <= n;i++) {
    		if(i!=1) cout << " ";
    		cout << ans[i];
    	}
    	cout << "\n";
    }
    return 0;
}
