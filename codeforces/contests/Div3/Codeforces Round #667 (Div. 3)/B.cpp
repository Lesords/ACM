#include<iostream>//ac
#include<cstring>
#include<cstdio>
#include<cmath>
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
int main() {
    int t;
    cin>>t;
    while(t--) {
        ll a,b,x,y,n;
        cin>>a>>b>>x>>y>>n;
        ll mina = max(x,a-n),minb = max(y,b-n);
        ll numa = a-mina, numb = b-minb;
        if(a-x+b-y<=n) cout<<x*y<<endl;
        else {
            ll ans = min(mina*(b-(n-numa)),minb*(a-(n-numb)));
            cout<<ans<<endl;
        }
    }
	return 0;
}
