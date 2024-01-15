#include<iostream>//ac
#include<vector>
#include<algorithm>
#define fi first
#define se second
#define pii pair<int, int>
using namespace std;

//题解：计算连通块数量，结果为连通块数量-1
//寻找是否在x轴和y轴有相同方向的点即为联通

const int MAXN = 1005;
int a[MAXN][MAXN],vis[MAXN][MAXN];
vector<pii> v;
void dfs(int x,int y) {
    vis[x][y] = 1;//标记当前点
    for(int i = 1;i <= 1000;i++) {//相同的x轴寻找点
        if(a[x][i]&&!vis[x][i]) {
            dfs(x,i);
        }
    }
    for(int i = 1;i <= 1000;i++) {//相同的y轴寻找点
        if(a[i][y]&&!vis[i][y]) {
            dfs(i,y);
        }
    }
}
int main() {
    int n,ans = 0;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        int x,y;
        cin>>x>>y;
        v.push_back({x,y});
        a[x][y] = 1;//记录点
    }
    for(int i = 0;i < v.size();i++) {
        int x = v[i].fi;
        int y = v[i].se;
        if(vis[x][y]) continue;//已标记，则跳过
        dfs(x,y);
        ans++;//统计连通块数量
    }
    cout<<ans-1;
    return 0;
}
