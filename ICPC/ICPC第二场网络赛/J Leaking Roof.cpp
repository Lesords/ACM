#include<iostream>//ac
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<utility>
#include<bitset>
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define eps 1e-8
using namespace std;
const int MAXN = 505;
const int MAXV = 1e4+5;
struct node{
	int x,y;
};
vector<node> g[MAXV];
int a[MAXN][MAXN];
bool vis[MAXN][MAXN];
double ans[MAXN][MAXN];
int nextt[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
int main() {
	int n, m;
	cin>>n>>m;
	int minn = INF, maxx = 0;
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) {
			cin>>a[i][j];
			minn = min(minn, a[i][j]);
			maxx = max(maxx, a[i][j]);
			g[a[i][j]].push_back({i, j});
			ans[i][j] = m;
		}
	}
	for(int i = maxx;i >= minn;i--) {
		if(g[i].empty()) continue;
		for(auto v:g[i]) {
			if(a[v.x][v.y]==0) continue;
			int num = 0;
			vector<node> tt;
			for(int j = 0;j < 4;j++) {
				int tx = v.x + nextt[j][0];
				int ty = v.y + nextt[j][1];
				if(tx < 1||tx > n||ty < 1||ty > n) continue;
				if(a[tx][ty]>=a[v.x][v.y]) continue;
				tt.push_back({tx, ty});
				num++;
			}
			double siz = tt.size();
			for(auto vv: tt) {
				ans[vv.x][vv.y] += ans[v.x][v.y]/siz;
			}
		}
	}
	
	
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) {
			if(a[i][j]!=0) printf("0 ");
			else printf("%.6f ", ans[i][j]+eps);
		}
		printf("\n");
	}
	return 0;
}