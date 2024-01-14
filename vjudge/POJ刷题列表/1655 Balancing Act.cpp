#include<iostream>//ac
#include<cstring>
#include<vector>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;

//题解：计算树的重心和最小分枝数，若有两个重心，则取小值

const int MAXN = 2e4+5;
vector<int> g[MAXN];
int num[MAXN],cent1,cent2,minn,n;//num记录当前分枝数（包括本身）
void dfs(int dot,int f) {//求重心和分枝数
    int maxx = 0;//计算当前点的最大分枝数
    num[dot] = 1;//自身
    for(int i = 0;i < g[dot].size();i++) {
        int now = g[dot][i];
        if(now==f) continue;//跳过父节点
        dfs(now,dot);
        num[dot] += num[now];//更新分枝数
        maxx = max(maxx,num[now]);//更行当前最大分枝数
    }
    maxx = max(maxx,n-num[dot]);//父节点往上分枝数
    if(maxx<minn) cent1 = dot,cent2 = 0,minn = maxx;//一个重心，则cent2为0
    else if(maxx==minn) cent2 = dot;
}
int main() {
    ios::sync_with_stdio(0);//加速
    cin.tie(0),cout.tie(0);
    int t;cin>>t;
    while(t--) {
        cin>>n;
        for(int i = 1;i < n;i++) {
            int a,b;
            cin>>a>>b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        cent1 = cent2 = 0,minn = INF;//初始化值
        dfs(1,0);
        if(!cent2) cout<<cent1<<" "<<minn<<endl;
        else cout<<min(cent1,cent2)<<" "<<minn<<endl;
        for(int i = 1;i <= n;i++) g[i].clear();//清空图
    }
    return 0;
}
