#include<iostream>//ac
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<set>
#include<utility>
#include<algorithm>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

//题解：计算连通块数量和去重后的数量
//记录连通块所有点的坐标然后所有点减去初始坐标，也就是说将连通图移到左上
//然后用set去重

const int MAXN = 1e3+5;
int n,m,vis[MAXN][MAXN];//vis判断是否标记过
int nextt[4][2] = {0,1,0,-1,1,0,-1,0};//四个方向
char s[MAXN][MAXN];
set<vector<pii>> st;//st去重，存连通块所有点
void bfs(int x,int y) {//记录连通块
    queue<pii> q;
    vector<pii> ord;//记录连通块的点
    q.push({x,y});//起点
    ord.push_back({x,y});//初始点坐标
    vis[x][y] = 1;//标记
    while(!q.empty()) {
        pii tmp = q.front();q.pop();
        for(int i = 0;i < 4;i++) {
            int tx = tmp.fi + nextt[i][0];
            int ty = tmp.se + nextt[i][1];
            if(tx<1||tx>n||ty<1||ty>m) continue;//越界
            if(vis[tx][ty]||s[tx][ty]=='0') continue;//已标记或为空
            vis[tx][ty] = 1;//标记
            ord.push_back({tx,ty});//记录点坐标
            q.push({tx,ty});
        }
    }
    //移至左上，以便查重
    for(int i = 0;i < ord.size();i++) ord[i].fi -= x,ord[i].se -= y;
    st.insert(ord);
}
int main() {
    while(cin>>n>>m&&n+m) {
        memset(vis,0,sizeof(vis));
        st.clear();//初始化
        for(int i = 1;i <= n;i++) {
            scanf("%s", s[i]+1);
        }
        int cnt = 0;
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= m;j++) {
                if(vis[i][j]) continue;//跳过已标记
                if(s[i][j]=='1') {//为黑块
                    cnt++,bfs(i,j);
                }
            }
        }
        //输出联通块数量和去重结果
        cout<<cnt<<" "<<st.size()<<"\n";
    }
    return 0;
}
