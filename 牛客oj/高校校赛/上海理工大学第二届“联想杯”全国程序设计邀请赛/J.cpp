#include<iostream>
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
ll poww(ll a,ll b) {
    ll ans = 1;
    while(b) {
        if(b&1) ans *= a;
        a *= a;
        b >>= 1;
    }
    return ans;
}
ll f(ll val,ll m) {
    ll num = val,cnt = 0,tmp = -1;
    while(val) {
        for(int i = 2;i <= val;i++) {
            if(val%i==0) {
                while(val%i==0) {
                    cnt++;
                    val /= i;
                }
                tmp = i;
                break;
            }
        }
        if(tmp!=-1) break;
    }
    ll tri = cnt-cnt/m;
    return num/poww(tmp,tri);
}
bool is_prim(int val) {
    for(int i = 2;i <= sqrt(val);i++) {
        if(val%i==0) return false;
    }
    return true;
}
int main() {
    ll ans = 0;
    int n,m,l;
    cin>>n>>m>>l;
    for(ll i = l+1;i <= l+n;i++) {
        if(is_prim(i)) {
            if(m!=1) ans += i-1;
        }
        else ans += i-f(i,m);
    }
    cout<<ans;
	return 0;
}
