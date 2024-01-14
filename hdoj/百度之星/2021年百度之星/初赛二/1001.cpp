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

//题解：找规律
//1: a b
//2: a+b    a-b     2^0

//3: (a+b)+(a-b)    (a+b)-(a-b)

//3: 2a     2b      2^1
//4: 2a+2b  2a-2b

//5: 4a     4b      2^2
//6: 4a+4b  4a-4b

//7: 8a     8b      2^3

const int MAXN = 2e5+5;
const int MOD = 998244353;
ll poww(ll a,ll b) {
    ll ans = 1;
    while(b) {
        if(b&1) {
            ans = (ans*a)%MOD;
        }
        a = (a*a)%MOD;
        b >>= 1;
    }
    return ans;
}
int main() {
    fast;
    int t;
    cin>>t;
    while(t--) {
        ll a,b,k;
        cin>>a>>b>>k;
        if(k==0) {
            cout<<a%MOD<<" "<<b%MOD<<"\n";
            continue;
        }
        k += 1;
        if(k&1) {
            ll val = k/2;//次方
            ll num = poww(2, val)%MOD;
            cout<<(num*a+MOD)%MOD<<" "<<(num*b+MOD)%MOD<<"\n";
        }
        else {
            ll val = k/2-1;
            ll num = poww(2,val)%MOD;
            ll ans_a = (num*a%MOD+num*b%MOD+MOD)%MOD;
            ll ans_b = (num*a%MOD-num*b%MOD+MOD)%MOD;
            cout<<ans_a<<" "<<ans_b<<"\n";
        }
    }
	return 0;
}
