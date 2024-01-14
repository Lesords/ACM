#include<iostream>//ac
#include<cmath>
#include<set>
#include<algorithm>
#define ll long long
using namespace std;
ll n;
set<ll> num;
void dfs(ll endd, ll pos,ll val) {
    if(pos==endd) {
        int tmp = val,siz = 1;
        while(tmp) {
            siz *= 10;
            tmp /= 10;
        }
        if(val*siz+val<=n) {
            num.insert(val*siz+val);
        }
        return;
    }
    int l = 0;
    if(val==0) l = 1;
    for(int i = l;i <= 9;i++) {
        dfs(endd, pos+1, val*10+i);
    }
}
int main() {
    cin>>n;
    ll tmp = n,cnt = 0;
    while(tmp) {
        cnt++,tmp/=10;
    }
    for(int i = 2;i <= cnt;i++) {
        dfs(i/2ll,0ll,0ll);
    }
    cout<<num.size();
    return 0;
}
