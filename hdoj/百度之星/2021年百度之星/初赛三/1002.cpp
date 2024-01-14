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
struct node{
    int x,y;
};
char a[15][15];
int vis[15][15],ans,n;
int nextt[2][2] = {1,0,0,1};
vector<node> path;
bool judge(int x,int y) {
    if(x>n||y>n) return false;
    if(a[x][y]=='#') return false;
    if(vis[x][y]) return false;
    return true;
}
int dfs(int x,int y) {
    if(x==n&&y==n) {
        return 1;
    }
    for(int i = 0;i < 2;i++) {
        int tx = x+nextt[i][0];
        int ty = y+nextt[i][1];
        if(judge(tx,ty)) {
            //标记的情况是有一个不为n即可不是两个都不为n
            //不然n行和n列的都无法标记到
            if(tx!=n||ty!=n) vis[tx][ty] = 1;
            if(dfs(tx,ty)) return 1;
            vis[tx][ty] = 0;//当前不可信，则需重新置0
        }
    }
    return 0;
}
int main() {
    fast;
    int t;
    cin>>t;
    while(t--) {
        cin>>n;
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= n;j++) cin>>a[i][j];
        }
        if(a[1][1]=='#'||a[n][n]=='#') {
            cout<<"0\n";
            continue;
        }
        memset(vis, 0,sizeof(vis));
        ans = 0;
        //遍历计算
        while(dfs(1,1)) ans++;
        cout<<ans<<"\n";
    }
	return 0;
}
