#include<iostream>//ac
#include<cstring>
#include<deque>
#include<algorithm>
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std

//题解：01-bfs
//对于01-bfs而言，就是说在bfs时，对应的操作有的是需要花费的，有的是不需要花费的
//简单的来说，就是步骤有权值为0和权值为1的情况
//对于权值为0的情况相对而言就是步数少的情况，权值为1的情况就是步数多的情况
//那么也就是权值为0的情况需要放在队首（较优解
//权值为1的情况需要放在队末
//所以需要用到双端队列（stl中可用deque

//对于本题而言，上下走就是权值为0的步骤，左右走就是权值为1的步骤
//那么每次记录的时候可以记录对应 左 和 右 的可走步数
//判断的时候，需要筛掉所有 左 和 右 步数不符合情况的值

const int MAXN = 2e3+5;
struct node{
    int x,y,l,r;//(x,y)为当前坐标
                //l表示可以向左走的步数，r表示可以向右走的步数
};
char a[MAXN][MAXN];
int vis[MAXN][MAXN];//vis标记当前点是否走过
int nextt[4][2] = {0,1,0,-1,1,0,-1,0};//四个方向，0为向右走，1位向左走，2、3为上下走
int main() {
    fast;//加速！！！
    int n,m,r,c,L,R;
    cin>>n>>m>>r>>c>>L>>R;
    for(int i = 1;i <= n;i++) {
        cin>>a[i]+1;//直接读取一行！！！
        //两个优化，从 1638ms 优化到 140ms
    }

    deque<node> q;
    int ans = 0;
    vis[r][c] = 1;//标记起点
    q.push_back({r,c,L,R});//添加起点
    while(!q.empty()) {
        node tmp = q.front();
        q.pop_front();
        if(tmp.l<0||tmp.r<0) continue;//跳过步数为负的情况，因为步数为负不满足条件
        ans++;//记录所有点
        for(int i = 0;i < 4;i++) {
            int tx = tmp.x+nextt[i][0];
            int ty = tmp.y+nextt[i][1];
            if(tx<1||tx>n||ty<1||ty>m) continue;//越界，跳过
            if(a[tx][ty]=='*'||vis[tx][ty]) continue;//为墙或已访问，跳过
            vis[tx][ty] = 1;//标记当前点
            //根据当前的方向来判断是否修改对应的值
            //左右走，有算权值，放在队尾
            if(i==0) {//R
                q.push_back({tx,ty,tmp.l,tmp.r-1});
            }
            else if(i==1) {//L
                q.push_back({tx,ty,tmp.l-1,tmp.r});
            }
            else {//上下走，无需修改值，放在队首
                q.push_front({tx,ty,tmp.l,tmp.r});
            }
        }
    }
    cout<<ans;
    return 0;
}
