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
int n,a[11],b[11],ans;
int vis[11];
int gcd(int a,int b) {
    return b==0?a:gcd(b,a%b);
}
void dfs(int pos,int num) {
    if(pos>n) {
        ans = max(ans,num);
        return;
    }
    dfs(pos+1,num);
    for(int i = 1;i <= n;i++) {
        if(vis[i]) continue;
        vis[i] = 1;
        if(gcd(a[pos],b[i])>1) {
            dfs(pos+1, num+1);
        }
        vis[i] = 0;
    }
}
int main() {
    cin>>n;
    for(int i = 1;i <= n;i++) {
        cin>>a[i];
    }
    for(int i = 1;i <= n;i++) cin>>b[i];
    dfs(1,0);
    cout<<ans;
	return 0;
}

