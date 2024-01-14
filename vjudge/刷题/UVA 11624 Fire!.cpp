#include<cstdio>//ac
#include<cstring>
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

//题解：先bfs预处理部分格子着火的时间，不着火的初始化为-1
//然后继续bfs人，先判断到底某点的时候是否已经着火，然后再判断Joe是否可以到达边界即可

const int MAXN = 1005;
struct node{
    int x,y,step;
    friend bool operator < (node a,node b) {
    	return a.step > b.step;//步数小的优先
    }
};
int r,c,fire[MAXN][MAXN],vis[MAXN][MAXN];//fire判断当前点什么时候起火，vis判断是否经过
int nextt[4][2] = {1,0,0,1,-1,0,0,-1};
char s[MAXN][MAXN];
int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        scanf("%d%d",&r,&c);//r行，c列
        for(int i = 1;i <= r;i++) scanf("%s",s[i]+1);//从1开始存字符串
        priority_queue<node> tim;//先bfs初始化着火的时间
        int sx,sy,num=0;
        for(int i = 1;i <= r;i++) {
            for(int j = 1;j <= c;j++) {
                if(s[i][j]=='J') sx=i,sy=j;//记录Joe的位置
                if(s[i][j]=='F') {//记录所有火的位置，入队列
                    fire[i][j] = 0,tim.push(node{i,j,0});
                    num++;//num记录火的初始数量
                    vis[i][j] = 1;//标记一次
                }
                else fire[i][j] = -1,vis[i][j]=0;
            }
        }
        while(!tim.empty()) {//bfs遍历所有的火
            node tmp = tim.top();
            tim.pop();
            for(int i = 0;i < 4;i++) {
                int tx = tmp.x + nextt[i][0];
                int ty = tmp.y + nextt[i][1];
                if(tx<1||tx>r||ty<1||ty>c) continue;//越界
                if(vis[tx][ty]>num||s[tx][ty]=='#') continue;//大于num说明有火重复蔓延了，跳过墙
                if(fire[tx][ty]!=-1&&fire[tx][ty]<=tmp.step+1) continue;
                //当前位置有火，且着火时间更快
                vis[tx][ty]++;
                fire[tx][ty] = tmp.step+1;
                tim.push(node{tx,ty,fire[tx][ty]});
            }
        }
        memset(vis,0,sizeof(vis));//清空标记数组
        priority_queue<node> person;
        person.push(node{sx,sy,0});
        vis[sx][sy] = 1;
        int ans = 0;//初始化为0
        while(!person.empty()) {
            node tmp = person.top();
            person.pop();
            if(tmp.x==1||tmp.x==r||tmp.y==1||tmp.y==c) {//到达边界，满足条件
                ans = tmp.step+1;break;
            }
            for(int i = 0;i < 4;i++) {
                int tx = tmp.x + nextt[i][0];
                int ty = tmp.y + nextt[i][1];
                if(tx<1||tx>r||ty<1||ty>c) continue;//越界
                if(s[tx][ty]=='#'||vis[tx][ty]) continue;//只有一个人，所以访问过的就跳过
                if(fire[tx][ty]!=-1&&tmp.step+1>=fire[tx][ty]) continue;//到达之前着火
                vis[tx][ty] = 1;
                person.push(node{tx,ty,tmp.step+1});
            }
        }
        if(ans==0) cout<<"IMPOSSIBLE\n";//0为无可能
        else cout<<ans<<"\n";
    }
    return 0;
}
