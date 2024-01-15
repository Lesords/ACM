#include<iostream>//ac
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

//题解：拓扑排序，难点在于建边的思路
//在每列车中首尾停靠的范围内选择未停靠的向停靠的连接
//那么对于这个连接之后的图来说，直接跑拓扑排序，计算有几层即可

const int MAXN = 1e3+2;
struct node{
    int id,pos;                         //id为当前点编号，pos为层数
    friend bool operator < (node a,node b) {
        return a.pos > b.pos;
    }
};
int a[MAXN],in[MAXN],g[MAXN][MAXN];     //in记录入度，g存图（方便去重
bool vis[MAXN];                         //记录当前点是否停靠过，停靠则为1
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= m;i++) {
        int num;
        cin>>num;
        for(int j = 1;j <= num;j++) {
            cin>>a[j];
            vis[a[j]] = 1;                      //记录停靠点
        }
        for(int j = a[1];j <= a[num];j++) {     //在首尾范围内寻找！！！
            if(vis[j]==0) {                     //非停靠点
                for(int k = 1;k <= num;k++) {
                    //每条边只需要记录一次入度！！！
                    if(!g[j][a[k]]) in[a[k]]++;
                    g[j][a[k]] = 1;             //建边
                }
            }
            vis[j] = 0;                         //清空，无需初始化
        }
    }
    priority_queue<node> q;
    for(int i = 1;i <= n;i++) {                 //将入度为0的点放入队列中，默认层数为1
        if(in[i]==0) q.push({i,1});
    }
    int ans = 0;
    node tmp;
    while(!q.empty()) {
        tmp = q.top();
        q.pop();
        ans = max(ans, tmp.pos);                //更新最大层数
        for(int i = 1;i <= n;i++) {
            if(i==tmp.id) continue;             //跳过本身点
            if(g[tmp.id][i]) {                  //tmp.id到i存在边
                if(--in[i]==0) {                //若入度为0，则继续入队
                    q.push({i,tmp.pos+1});
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
