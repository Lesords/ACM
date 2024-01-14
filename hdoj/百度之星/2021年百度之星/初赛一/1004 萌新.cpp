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
    fast;
    int t;
    cin>>t;
    while(t--) {
        ll n,m;
        cin>>n>>m;
        ll ans = max(n,m)-min(n,m);
        ans = n==m?n:ans;
        ll minn = ans;
        for(ll i = 2;i*i <= ans;i++) {
            if(ans%i==0) {
                minn = i;break;
            }
        }
        if(ans<=1&&minn<=1) {
            cout<<"-1 -1\n";
        }
        else {
            minn = n==m?2:minn;
            cout<<minn<<" "<<ans<<"\n";
        }
    }
	return 0;
}
