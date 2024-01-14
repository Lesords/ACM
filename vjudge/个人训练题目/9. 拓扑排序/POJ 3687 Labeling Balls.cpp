#include<iostream>//ac
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

//题解：反向建边+拓扑排序
//由于需要编号小的重量尽量小，所以可以使编号大的重量尽量大

const int MAXN = 205;
int n,m;
int vis[MAXN],in[MAXN],g[MAXN][MAXN],num[MAXN];
//vis记录是否已标记，in为入度，g存边，num记录对应编号球的重量
vector<int> ans;//ans记录拓扑序列
int main() {
    int t;
    cin>>t;
    while(t--) {
        cin>>n>>m;
        memset(vis,0,sizeof(vis));
        memset(in,0,sizeof(in));
        memset(g,0,sizeof(g));
        ans.clear();//初始化
        int flag = 0;
        for(int i = 1;i <= m;i++) {
            int x,y;
            cin>>x>>y;//反向建边，x入度++
            if(g[y][x]==0) in[x]++;//只需要一次（如果有重复的话）
            g[y][x] = 1;
            if(g[x][y]) flag = 1;//如果有反向的，则无解
        }
        if(flag) {
            cout<<"-1\n";
            continue;
        }
        priority_queue<int,vector<int>,less<int> > q;//降序，优先出大的
        for(int i = 1;i <= n;i++) if(in[i]==0) {//入度为0的入队列
            q.push(i);
        }
        while(!q.empty()) {
            int tmp = q.top();q.pop();
            if(vis[tmp]) continue;//跳过已标记的
            else vis[tmp] = 1;//否则需要标记
            ans.push_back(tmp);//记录拓扑序列
            for(int i = 1;i <= n;i++) {//遍历所有点
                if(i==tmp||vis[i]) continue;//跳过当前点和已经过的
                if(g[tmp][i]==0) continue;//跳过不存在边的
                --in[i];//指向点入度--
                if(in[i]==0) q.push(i);//入度为0则需要入队
            }
        }
        if(ans.size()!=n) {//不为n说明有环
            cout<<"-1\n";continue;
        }
        for(int i = 0;i < ans.size();i++) {//最开始的是最重的
            num[ans[i]] = n-i;
        }
        for(int i = 1;i <= n;i++) {//输出对应标签球的重量！！！
            if(i!=1) cout<<" ";
            cout<<num[i];
        }
        cout<<"\n";
    }
    return 0;
}
/*
input:
7
10 5
4 1
8 1
7 8
4 1
2 8

5 4
5 1
4 2
1 3
2 3

4 0

4 1
1 1

4 2
1 2
2 1

4 1
2 1

4 1
3 2

output:
5 1 6 2 7 8 3 4 9 10

2 4 5 3 1

1 2 3 4

-1

-1

2 1 3 4

1 3 2 4
*/
