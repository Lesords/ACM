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
const int MAXN = 1005;
int n,m,vis[MAXN][MAXN],num[MAXN][MAXN];
int nextt[4][2] = {-1,0,0,-1,1,0,0,1};
char a[MAXN][MAXN];
void dfs(int x,int y) {
    int tx,ty;
    if(a[x][y]=='W') tx = x+nextt[0][0],ty = y+nextt[0][1];
    if(a[x][y]=='A') tx = x+nextt[1][0],ty = y+nextt[1][1];
    if(a[x][y]=='S') tx = x+nextt[2][0],ty = y+nextt[2][1];
    if(a[x][y]=='D') tx = x+nextt[3][0],ty = y+nextt[3][1];
    if(vis[tx][ty]) {
        num[x][y] = num[tx][ty];
        return;
    }
    if(tx<1||tx>n||ty<1||ty>m) {
        num[x][y] = 1;return;
    }
    vis [tx][ty] = 1;
    dfs(tx,ty);
    num[x][y] = num[tx][ty];
}
int main() {
    cin>>n>>m;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) cin>>a[i][j];
    }
    int ans = 0;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            if(vis[i][j]) {
                ans += num[i][j];continue;
            }
            vis[i][j] = 1;
            dfs(i,j);
            ans += num[i][j];
        }
    }
    cout<<ans<<endl;
	return 0;
}
