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
ll a[MAXN];
int main() {
    fast;
    int t;
    cin>>t;
    for(int cas = 1;cas <= t;cas++) {
        ll n,m,k;
        cin>>n>>m>>k;
        for(int i = 1;i <= n;i++) cin>>a[i];
        cout<<"Case #"<<cas<<":\n";
        sort(a+1, a+1+n);
        int last = 0;
        for(int i = 1;i <= n;i++) {
            if(a[i]<=m) {
                last = i;
            }
        }
        if(last==0) {
            cout<<"madan!\n";continue;
        }
        int ok = 1;
        for(int i = last+1;i <= n;i++) {
            if(a[i]-a[i-1]>k) {
                ok = 0;break;
            }
            if(k) k--;
        }
        if(ok) cout<<"why am I so diao?\n";
        else cout<<"madan!\n";
    }
	return 0;
}
