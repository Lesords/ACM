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
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;

//题解：dfs计算重心，若重心只有一个，则选择任一边删增即可
//否则需将 子重心 中的叶节点连接到 父重心 中去

const int MAXN = 1e5+5;
vector<int> g[MAXN];//存图
int fa[MAXN],num[MAXN],n,minn,cent1,cent2,son;
//fa保存对应点的父节点，num记录当前节点分支总数（本身+所有子孙节点）
//minn记录删除当前点可获得的最大节点分支数
//cent1为第一个重心，cent2为第二个重心，son为 子重心 的叶节点
void dfs(int dot,int f) {//计算重心和父节点
    int maxx = 0;//记录删除dot点可获得的最大分枝数
    num[dot] = 1;//本身为一个点
    for(int i = 0;i < g[dot].size();i++) {
        int now = g[dot][i];
        if(now==f) continue;//跳过父节点
        fa[now] = dot;
        dfs(now,dot);
        maxx = max(maxx,num[now]);//更新 最大分枝数
        num[dot] += num[now];//更新分支总数
    }
    maxx = max(maxx,n-num[dot]);//父节点向上的分数数量
    if(maxx<minn) cent1 = dot,minn = maxx,cent2 = 0;//只有一个重心，cent2需为0
    else if(maxx==minn) cent2 = dot;
}
void dfs2(int dot,int f) {//寻找子重心的叶节点
    if(g[dot].size()==1) {//找到叶节点直接返回
        son = dot;return;//更新son的值
    }
    for(int i = 0;i < g[dot].size();i++) {
        if(g[dot][i]==f) continue;//跳过父节点
        dfs2(g[dot][i],dot);
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;cin>>t;
    while(t--) {
        cin>>n;
        for(int i = 1;i < n;i++) {
            int x,y;
            cin>>x>>y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        cent1 = cent2 = 0,minn = INF;//初始化
        dfs(1,0);//初始节点的父节点设为0
        if(!cent2) {//只有一个重心
            cout<<cent1<<" "<<g[cent1][0]<<"\n"<<cent1<<" "<<g[cent1][0]<<"\n";
        }
        else {
            if(fa[cent2]!=cent1) swap(cent1,cent2);
            dfs2(cent2,cent1);//令cent2为子重心，否则交换两者的值
            cout<<fa[son]<<" "<<son<<"\n"<<cent1<<" "<<son<<"\n";
        }
        for(int i = 1;i <= n;i++) g[i].clear(),fa[i] = 0;//清空原图及父节点值
    }
	return 0;
}
