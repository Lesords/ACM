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

//题解：01-bfs
//本题中如果下一个点为 #，表示需要花费一次冲击，即为有权值的情况
//因为操作的目标是下一个位置，所以可以在下一个位置对应的情况修改！！！
//由于冲击的范围为 2*2，所以对于这种情况可以转换为冲击一次之后
//到达 冲击范围 内的某个点时，花费了一个冲击
//由于 冲击方向 任意，所以对应当前位置共有四种冲击方式
//对应为位置为 3*3 的大小，对于当前位置而言为 -1 0 1（横纵一致，共9个位置）
//对于 . 的情况来说，无需冲击直接到达

const int MAXN = 505;
const int MOD = 1e9+7;
struct node{
    int x,y,num;//(x,y)为坐标，num为冲击次数
};
char a[MAXN][MAXN];
int h,w,vis[MAXN][MAXN];//vis记录当前点是否访问过
int nextt[4][2] = {1,0,0,1,-1,0,0,-1};
int main() {
    cin>>h>>w;
    for(int i = 1;i <= h;i++) {
        cin>>a[i]+1;
    }
    deque<node> q;
    q.push_back({1,1,0});//起点
    while(!q.empty()) {
        node tmp = q.front();
        q.pop_front();
        if(tmp.x==h&&tmp.y==w) {//到达终点，直接输出次数
            cout<<tmp.num<<"\n";
            break;
        }
        if(vis[tmp.x][tmp.y]) continue;//跳过已访问的
        vis[tmp.x][tmp.y] = 1;//标记访问
        //因为队列前面访问的是最优的，所以根据顺序标记即可！！！
        for(int i = 0;i < 4;i++) {
            int tx = tmp.x+nextt[i][0];
            int ty = tmp.y+nextt[i][1];
            if(tx<1||tx>h||ty<1||ty>w) continue;//越界，跳过
            if(vis[tx][ty]) continue;//已访问，跳过
            if(a[tx][ty]=='#') {//如果障碍，需要冲击
                //由于当前是对 (tx,ty) 操作的，所以对应的位置与 (tx,ty) 有关！！！
                //即可放在当前位置一起计算，无需另外讨论！！！
                for(int j = -1;j <= 1;j++) {//对应9个点
                    for(int k = -1;k <= 1;k++) {
                        int nx = tx+j;//(nx,ny)为冲击的范围坐标
                        int ny = ty+k;
                        if(nx<1||nx>h||ny<1||ny>w) continue;//越界，跳过
                        if(vis[nx][ny]) continue;//已标记，表示当前不是最优，跳过
                        q.push_back({nx,ny,tmp.num+1});//放在队尾
                    }
                }
            }
            else {
                //无需操作，直接放在队首
                q.push_front({tx,ty,tmp.num});
            }
        }
    }
	return 0;
}
