#include<iostream>//ac
#include<queue>
#include<utility>
#include<set>
#include<algorithm>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

//题解：bfs计算所有联通数量（与第一块砖相连）

int w,h,sx,sy;
int nextt[4][2] = {0,1,1,0,0,-1,-1,0};//四个方向
char a[25][25];
set<pii> st;//记录已经历过的点
int main() {
    cin>>w>>h;
    for(int i = 1;i <= h;i++) {
        for(int j = 1;j <= w;j++) {
            cin>>a[i][j];
            if(a[i][j]=='@') sx = i,sy = j;//记录起点
        }
    }
    queue<pii> q;
    q.push({sx,sy});//起点入队
    int ans = 0;
    while(!q.empty()) {
        pii tmp = q.front();q.pop();
        if(st.count({tmp.fi, tmp.se})) continue;//跳过已遍历的
        else st.insert({tmp.fi, tmp.se});//否则标记
        ans++;//答案++
        for(int i = 0;i < 4;i++) {//四个方向
            int tx = tmp.fi + nextt[i][0];
            int ty = tmp.se + nextt[i][1];
            if(tx<1||tx>h||ty<1||ty>w) continue;//越界
            if(a[tx][ty]!='.') continue;//跳过不为砖的
            q.push({tx,ty});
        }
    }
    cout<<ans<<"\n";
    return 0;
}
