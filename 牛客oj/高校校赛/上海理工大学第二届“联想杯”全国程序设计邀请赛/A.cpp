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
const int MAXN = 1e5+5;
const int MOD = 1e9+7;
int a[MAXN];
map<int,int> pos;
vector<int> g[MAXN];
int main() {
    int n,k;
    int cnt = 0;
    cin>>n>>k;
    for(int i = 1;i <= n;i++) {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    n = unique(a+1,a+1+n)-a-1;
    for(int i = 1;i <= n;i++) {
        if(i==1) {
            pos[a[i]] = ++cnt;
            g[cnt].push_back(a[i]);
        }
        else {
            int last = a[i]-k;
            if(pos.find(last)!=pos.end()) {
                pos[a[i]] = pos[last];
                int pp = pos[last];
                if(g[pp][g[pp].size()-1]==a[i]) continue;
                g[pos[last]].push_back(a[i]);
            }
            else {
                pos[a[i]] = ++cnt;
                g[cnt].push_back(a[i]);
            }
        }
    }
    int ans = 0;
    for(int i = 1;i <= cnt;i++) {
        ans = max(ans, (int)g[i].size());
    }
    cout<<ans;
	return 0;
}
