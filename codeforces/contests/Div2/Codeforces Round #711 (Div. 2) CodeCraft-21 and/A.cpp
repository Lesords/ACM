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
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;
const int MAXN = 1e5+5;
ll gcd(ll a,ll b) {
    return a%b==0?b:gcd(b,a%b);
}
ll getS(ll val) {
    ll ans = 0;
    while(val) {
        ans += val%10;
        val /= 10;
    }
    return ans;
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        ll n;
        cin>>n;
        for(ll i = n;i;i++) {
            ll val = getS(i);
            if(gcd(val,i)>1) {
                cout<<i<<"\n";
                break;
            }
        }
    }
	return 0;
}
