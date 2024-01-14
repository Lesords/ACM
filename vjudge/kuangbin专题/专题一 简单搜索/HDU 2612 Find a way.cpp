#include<iostream>//ac
#include<cstring>
#include<queue>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;

//题解：从Y和M的位置分别进行bfs，到达 每个KCF 都判断总时长！！！
//防止出现部分点一个人先到，另外一个人晚到！！！（要取和）

const int MAXN = 205;
struct node{
    int x,y,step;
    friend bool operator < (node a,node b) {
        return a.step > b.step;//优先步数少的
    }
};
char s[MAXN][MAXN];//t1和t2也可当做标记使用
int n,m,t1[MAXN][MAXN],t2[MAXN][MAXN];//t1记录Y到达的时间，t2记录M到达的时间
int nextt[4][2] = {0,1,0,-1,1,0,-1,0};//4个方向
int main() {
    ios::sync_with_stdio(0);//加速
    cin.tie(0),cout.tie(0);
    while(cin>>n>>m) {
        for(int i = 1;i <= n;i++) cin>>s[i]+1;
        memset(t1,-1,sizeof(t1));//初始化为-1，表示还未到达
        memset(t2,-1,sizeof(t2));
        int ax,ay,bx,by;
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= m;j++) {
                if(s[i][j]=='Y') ax = i,ay = j;
                if(s[i][j]=='M') bx = i,by = j;
            }
        }
        priority_queue<node> q1,q2;//初始化对应优先队列
        node tmp = {ax,ay,0};//两个人的起点的时间都为0
        q1.push(tmp);
        tmp = {bx,by,0};
        q2.push(tmp);
        t1[ax][ay] = t2[bx][by] = 0;//记录起点时间为0
        int ans = INF;//结果初始化为INF
        while(!q1.empty()||!q2.empty()) {//两个有一个不为空，则继续bfs
            node tmp1,tmp2;
            if(!q1.empty()) {//第一个不为空，则bfs
                tmp1 = q1.top();q1.pop();
                for(int i = 0;i < 4;i++) {//四个方向
                    int tx = tmp1.x+nextt[i][0];
                    int ty = tmp1.y+nextt[i][1];
                    if(tx<1||tx>n||ty<1||ty>m) continue;//越界
                    //已访问或不可走，则跳过
                    if(t1[tx][ty]!=-1||s[tx][ty]=='#') continue;
                    t1[tx][ty] = tmp1.step+1;//时间+1
                    if(s[tx][ty]=='@'&&t2[tx][ty]!=-1) {
                        //两者都到达KCF，则更新答案
                        ans = min(ans,tmp1.step+1+t2[tx][ty]);
                    }
                    node tt = {tx,ty,tmp1.step+1};
                    q1.push(tt);//入队
                }
            }
            if(!q2.empty()) {//第二个不为空，则bfs
                tmp2 = q2.top();q2.pop();
                for(int i = 0;i < 4;i++) {//四个方向
                    int tx = tmp2.x+nextt[i][0];
                    int ty = tmp2.y+nextt[i][1];
                    if(tx<1||tx>n||ty<1||ty>m) continue;//越界
                    //已访问或不可走，则跳过
                    if(t2[tx][ty]!=-1||s[tx][ty]=='#') continue;
                    t2[tx][ty] = tmp2.step+1;//时间+1
                    if(s[tx][ty]=='@'&&t1[tx][ty]!=-1) {
                        //两者都到达KCF，则更新答案
                        ans = min(ans,tmp2.step+1+t1[tx][ty]);
                    }
                    node tt = {tx,ty,tmp2.step+1};
                    q2.push(tt);//入队
                }
            }
        }
        cout<<ans*11<<"\n";//结果需乘11
    }
    return 0;
}
