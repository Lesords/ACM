#include<iostream>//ac
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;

//题解：先用dfs计算连通块，小于2的和大于2的都特判
//剩余的枚举所有的两个点来bfs计算最快燃烧完的值

struct node{
    int x,y,step;
    friend bool operator < (node a,node b) {
        return a.step > b.step;//优先步数少的
    }
};
char s[15][15];
int n,m,vis[15][15];
int nextt[4][2] = {0,1,0,-1,1,0,-1,0};//四个方向
void dfs(int x,int y) {//计算有几个连通块
    vis[x][y] = 1;//标记当前点
    for(int i = 0;i < 4;i++) {
        int tx = x+nextt[i][0];
        int ty = y+nextt[i][1];
        if(tx<1||tx>n||ty<1||ty>m) continue;//越界
        if(s[tx][ty]=='.'||vis[tx][ty]) continue;//空地或已标记
        vis[tx][ty] = 1;//标记指向点
        dfs(tx,ty);
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;cin>>t;
    for(int cas = 1;cas <= t;cas++) {
        cin>>n>>m;
        for(int i = 1;i <= n;i++) cin>>s[i]+1;
        vector<node> grass;//记录所有草地的位置
        int num = 0;
        memset(vis,0,sizeof(vis));
        for(int i = 1;i <= n;i++) {//记录草地的时候可以一起计算联通块
            for(int j = 1;j <= m;j++) {
                if(s[i][j]=='#') {
                    if(vis[i][j]==0) {
                        dfs(i,j);num++;
                    }
                    node tmp = {i,j,0};
                    grass.push_back(tmp);
                }
            }
        }
        if(num>2) {//超过两个联通块即无解
            cout<<"Case "<<cas<<": "<<-1<<"\n";
            continue;
        }
        if(grass.size()<=2) {//少于两个即可立即烧完
            cout<<"Case "<<cas<<": "<<0<<"\n";
            continue;
        }
        int ans = INF;//记录最后的答案
        for(int i = 0;i < grass.size();i++) {//枚举所有的两个点
            for(int j = i+1;j < grass.size();j++) {
                memset(vis,0,sizeof(vis));
                priority_queue<node> q;
                int cnt = 2;//初始点两个
                q.push(grass[i]);
                q.push(grass[j]);
                vis[grass[i].x][grass[i].y] = 1;
                vis[grass[j].x][grass[j].y] = 1;//标记两个点
                while(!q.empty()) {
                    node tmp = q.top();q.pop();
                    for(int i = 0;i < 4;i++) {
                        int tx = tmp.x+nextt[i][0];
                        int ty = tmp.y+nextt[i][1];
                        if(tx<1||tx>n||ty<1||ty>m) continue;//越界
                        if(s[tx][ty]=='.'||vis[tx][ty]) continue;//空地或已标记
                        vis[tx][ty] = 1;//标记当前点
                        cnt++;//记录已经燃烧的数量
                        if(cnt==grass.size()) {//如果等于总草地的数量则更新答案
                            ans = min(ans,tmp.step+1);
                        }
                        node tt = {tx,ty,tmp.step+1};
                        q.push(tt);//入队
                    }
                }
            }
        }
        //需要判断是否为INF！！！
        cout<<"Case "<<cas<<": "<<(ans==INF?-1:ans)<<"\n";
    }
    return 0;
}
