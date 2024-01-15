#include<iostream>//ac
#include<cstdio>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;
const int MAXN = 50;
ll a[MAXN],b[MAXN];
int main() {
    int t,n;
    cin>>t;
    while(t--) {
        cin>>n;
        ll a_min = INF,b_min = INF;
        for(int i = 1;i <= n;i++) cin>>a[i],a_min = min(a_min,a[i]);
        for(int i = 1;i <= n;i++) cin>>b[i],b_min = min(b_min,b[i]);
        ll ans = 0;
        for(int i = 1;i <= n;i++) {
            a[i] -= a_min;
            b[i] -= b_min;
            ans += max(a[i],b[i]);
        }
        cout<<ans<<endl;
    }
	return 0;
}
