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
int ans,n,vis[100];
void dfs(int pos,int step) {
    if(step==n) {
        return (void) ans++;
    }
    //只遍历两个方向！！！
    int now = pos+step;
    if(now>n) now -= n;
    if(vis[now]==0) vis[now] = 1,dfs(now, step+1),vis[now] = 0;
    now = pos-step;
    if(now<1) now += n;
    if(vis[now]==0) vis[now] = 1,dfs(now, step+1),vis[now] = 0;
}
int main() {
    fast;
    int t;
    cin>>t;
    while(t--) {
        cin>>n;
        memset(vis, 0, sizeof(vis));
        ans = 0;
        vis[1] = 1;//起点标记！！！
        dfs(1,1);
        cout<<ans<<"\n";
    }
	return 0;
}
