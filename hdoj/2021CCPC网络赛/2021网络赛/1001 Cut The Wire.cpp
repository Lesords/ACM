#include<iostream>//ac
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
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
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int MAXN = 2e5+5;
const int MOD = 1e9+7;
int main() {
    int t;
    cin>>t;
    while(t--) {
    	ll n;
    	cin>>n;
    	ll ans = (n+1)/2;
    	ll Left = ceil(n/3.0);
    	ll num = n-Left+1;
    	if(Left&1) ans += ceil(num/2.0);
    	else ans += num/2;
    	cout<<ans<<"\n";
    }
    return 0;
}