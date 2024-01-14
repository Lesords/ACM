// Problem: Nightmare Ⅱ
// Contest: HDOJ
// URL: http://acm.hdu.edu.cn/showproblem.php?pid=3085
// Memory Limit: 32 MB
// Time Limit: 2000 ms
// 
// Author：Lese
// Time：2021-10-13 10:49:26

#include<iostream>//ac
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<sstream>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<utility>
#include<bitset>
#include<algorithm>
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define pii pair<int,int>
#define fi first
#define se second
#define eps 1e-6
#define lson rt<<1
#define rson rt<<1|1
using namespace std;
const int MAXN = 805;
const int MOD = 1e9+7;
const double pi = acos(double(-1));
struct node {
	int x, y, step;
	friend bool operator < (node a,node b) {
		return a.step > b.step;
	}
};
char a[MAXN][MAXN];
int gx, gy, bx, by, zx1, zx2, zy1, zy2;
int nextt[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
int vis[MAXN][MAXN], cnt, mark[MAXN][MAXN];
bool judge(int x, int y) {//判断当前位置是否被鬼占有
	if(abs(zx1-x)+abs(zy1-y) <= 2*cnt) return 1;
	if(abs(zx2-x)+abs(zy2-y) <= 2*cnt) return 1;
	return 0;
}
int main() {
	fast;
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		zx1 = 0;
		for(int i = 1;i <= n;i++) {
			for(int j = 1;j <= m;j++) {
				cin >> a[i][j];
				//记录女生和男生以及鬼的位置
				if(a[i][j] == 'G') gx = i, gy = j;
				else if(a[i][j] == 'M') bx = i, by = j;
				else if(a[i][j] == 'Z') {
					if(zx1 == 0) zx1 = i, zy1 = j;
					else zx2 = i, zy2 = j;
				}
				//初始化标记为空
				mark[i][j] = vis[i][j] = 0;
			}
		}
		priority_queue<node> one, two;
		one.push({bx, by, 0});
		two.push({gx, gy, 0});
		bool ok = 0;
		cnt = 0;//时间
		vis[bx][by] = mark[gx][gy] = 1;//标记对应男女的起点
		while(one.size()||two.size()) {//只要有一方可以走则继续
			cnt++;
			for(int i = 1;i <= 3;i++) {//男生可以走三步
				int siz = one.size();//记录当前队列中的数量（当前时间可以走的位置）
				for(int j = 1;j <= siz;j++) {
					int x = one.top().x;
					int y = one.top().y;
					int step = one.top().step;
					one.pop();
					if(judge(x, y)) continue;//当前位置也需要判断！！！
					for(int k = 0;k < 4;k++) {
						int tx = x + nextt[k][0];
						int ty = y + nextt[k][1];
						if(tx < 1 || tx > n || ty < 1 || ty > m) continue;
						if(a[tx][ty]=='X' || vis[tx][ty]) continue;
						if(judge(tx, ty)) continue;
						vis[tx][ty] = cnt;
						one.push({tx, ty, step+1});
					}
				}
			}
			int siz = two.size();//记录当前队列中的数量（当前时间可以走的位置）
			for(int i = 1;i <= siz;i++) {
				int x = two.top().x;
				int y = two.top().y;
				int step = two.top().step;
				two.pop();
				if(judge(x, y)) continue;//当前位置也需要判断！！！
				for(int j = 0;j < 4;j++) {//女生走一步
					int tx = x + nextt[j][0];
					int ty = y + nextt[j][1];
					if(tx < 1 || tx > n || ty < 1 || ty > m) continue;
					if(a[tx][ty]=='X' || mark[tx][ty]) continue;
					if(judge(tx, ty)) continue;
					mark[tx][ty] = cnt;
					if(vis[tx][ty]) {
						ok = 1;
						break;
					}
					two.push({tx, ty, step+1});
				}
				if(ok) break;
			}
			if(ok) break;
		}
		// 输出最短时间！！！
		if(ok) cout << cnt << "\n";
		else cout<<"-1\n";
	}
    return 0;
}
