#include<iostream>//ac
#include<cstring>
#include<map>
#include<queue>
#include<set>
#include<utility>
#include<algorithm>
#define INF 0x3f3f3f3f
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

//题解：利用map嵌套pair来存储传送装置传送的位置
//然后直接从起点开始bfs
//传送位置可以重复走，但是不能超过2次，其他位置只能走一次
//到达传送位置时，直接修改位置到传送的另一边去，两个位置都需要标记
//注意：记得判断越界，外圈不都是玉米

const int MAXN = 303;
struct node{
    int x,y,time;
    friend bool operator < (node a,node b) {
        return a.time > b.time;//优先时间短的
    }
};
char s[MAXN][MAXN];         //记录给定的迷宫
map<pii,pii> num;           //记录对应传送位置指定的另一个传送位置
map<char,pii> pos_ch;       //记录对应字符上一次出现的位置
map<pii,int> vis;           //记录当前位置走过的次数
int n,m,sx,sy;
int nextt[4][2] = {0,1,0,-1,1,0,-1,0};//四个方向
int main() {
    cin>>n>>m;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            cin>>s[i][j];
            if(s[i][j]=='@') {                              //记录起点
                sx = i,sy = j;
            }
            if(s[i][j]>='A'&&s[i][j]<='Z') {                //记录传送位置
                if(pos_ch.find(s[i][j])==pos_ch.end()) {    //第一次记录，直接保存位置即可
                    pos_ch[s[i][j]] = {i,j};
                }
                else {                                      //第二次需要互相指定位置
                    num[pos_ch[s[i][j]]] = {i,j};
                    num[{i,j}] = pos_ch[s[i][j]];
                }
            }
        }
    }
    int ans = INF;                                          //初始化为无穷大
    priority_queue<node> q;
    q.push({sx,sy,0});                                      //起点
    vis[{sx,sy}]++;                                         //标记起点
    while(!q.empty()) {
        node tmp = q.top();
        q.pop();
        if(s[tmp.x][tmp.y]=='=') {                          //到达终点，更新答案，直接结束
            ans = tmp.time;
            break;
        }
        for(int i = 0;i < 4;i++) {                          //四个方向
            int tx = tmp.x + nextt[i][0];                   //指定点
            int ty = tmp.y + nextt[i][1];
            if(tx<1||tx>n||ty<1||ty>m) continue;            //需要判越界！！！
            if(s[tx][ty]=='#') continue;                    //跳过玉米
            if(s[tx][ty]=='.'&&vis.find({tx,ty})!=vis.end()) continue;//草地并且已走过，直接跳过
            if(vis[{tx,ty}]>2) continue;                    //不为草地即为传送装置，超过两次，直接跳过
            vis[{tx,ty}]++;                                 //记录当前位置
            if(s[tx][ty]>='A'&&s[tx][ty]<='Z') {            //若当前为传送装置
                pii tpos = num[{tx,ty}];                    //获取指向位置
                tx = tpos.fi;                               //更新位置
                ty = tpos.se;
                vis[{tx,ty}]++;                             //标记
            }
            q.push({tx,ty,tmp.time+1});                     //再次入队
        }
    }
    cout<<ans;
    return 0;
}
/*
样例：
4 5
#####
##W.#
#@W##
##=##
*/
