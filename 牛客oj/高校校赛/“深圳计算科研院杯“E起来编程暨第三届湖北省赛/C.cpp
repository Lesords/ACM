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
    int t;
    cin>>t;
    while(t--) {
        int n,k;
        cin>>n>>k;
        map<int,int> mp;
        for(int i = -n;i <= n;i++) {
            for(int j = -n;j <= n;j++) {
                mp[i*(i+1)+j*(j+1)]++;
            }
        }
        int ans = 0;
        for(int i = -n;i <= n;i++) {
            for(int j = -n;j <= n;j++) {
                int val = i*(i+1)+j*(j+1);
                ans += mp[val*k];
            }
        }
        cout<<ans<<"\n";
    }
	return 0;
}
