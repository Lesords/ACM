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
        int a,b,c;
        cin>>a>>b>>c;
        if(a>b) swap(a,b);
        int dis = b-a-1;
        if(a-1>dis) {
            cout<<"-1\n";continue;
        }
        int toOne = a-1;
        int siz = b+(dis-(toOne));
        if(max(b,c)>siz) {
            cout<<"-1\n";continue;
        }
        if(siz&1) cout<<"-1\n";
        else {
            int ans = c+dis+1;
            if(ans>siz) ans -= siz;
            cout<<ans<<"\n";
        }
    }
	return 0;
}
